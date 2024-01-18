#include<bits/stdc++.h>
using namespace std;

class node{
    public:
      //define kr dia sb kuch
      int data;
      node *left;
      node *right;
      
      //constructor banali : ek node ko taiyar kr dia hai
      node(int d){
         this -> data = d;
         this -> left = NULL;
         this -> right =NULL;
      }
};


node* preorder(node* root){
    node* temp = root;
    if(root != NULL){
        cout << temp->data <<endl;
        preorder(temp->left);
        preorder(temp->right);
    }
}

node* inorder(node* root){
    node* temp = root;
    if(root != NULL){
        inorder(temp->left);
        cout << temp->data <<endl;
        inorder(temp->right);
    }
}

node* postorder(node* root){
    node* temp = root;
    if(root != NULL){
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data <<endl;
    }
}

node* levelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //purana level traverse ho gya hai
            cout << endl;
            if(!q.empty()){
                q.push(NULL);//uske bhi kuch child nodes hai
            }
        }
        else{
            cout << temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

node* buildTree(node* root){
       cout<< "Enter the data"<<endl;
       int data;
       cin >> data;
       root = new node(data);//node ko data deke ready kr dia 

       if(data == -1){
        return NULL; //Null banane(leaf node) ke liye data ko -1 dedo
       }
       cout<< "Enter data for inserting in left of "<<data<<endl;
       root -> left = buildTree(root -> left);//isko bheja ready krne ke liye

       cout<< "Enter data for inserting in right of "<<data<<endl;
       root -> right = buildTree(root -> right);//isko bheja ready krne ke liye

       return root;

}

node* reverselevelorder(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
                s.push(NULL);
            }
        }
        else{
            s.push(temp);

            if(temp->left){
               q.push(temp->left);
            }
            if(temp->right){
               q.push(temp->right);
            }
        }

    }
    while(!s.empty())
    {
        node* temp1 = s.top();
        if(temp1 == NULL){
            cout << endl;
        }
        else{
            cout << temp1 -> data <<" ";
        }
        s.pop();
    }
}

int main(){
    node* root =NULL;

    root = buildTree(root);
    // cout<<"printing the level order traversal"<<endl;
    // levelorder(root);
    // cout<<"Printing the reverse level order traversal"<<endl;
    // reverselevelorder(root);
    cout<< "Preorder Traversal" <<" ";
    preorder(root);
    return 0;
}
#include<iostream>
#include<cstdlib>
using namespace std;
 
 
struct tree{
    tree* left;
    tree* right;
    tree* parent;
    int val;
};
 
void printPreorder(tree* root){
    if(root== NULL)return;
    cout << " " << root->val;
    printPreorder(root->left);
    printPreorder(root->right);
    return;
}
void printInorder(tree* root){
    if(root== NULL)return;
    printInorder(root->left);
    cout << " " << root->val;
    printInorder(root->right);
    return;
}
 
void find(int val, tree* root){
    if(root->val == val) cout << "yes" << endl;
    else{
        tree* next;
        if(val < root->val)next = root->left;
        else next = root->right;
 
        if(next)find(val,next);
        else cout << "no" << endl;
    }
}
 
void insert(int val, tree* root){
    tree* next;
    bool flag = val < root->val;
    if(flag)next = root->left;
    else next = root->right;
 
    if(next == NULL){
        tree* newNode = (tree*)malloc(sizeof(tree));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = root;
        if(flag)root->left = newNode;
        else root->right = newNode;
    }else{
        insert(val,next);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
 
    tree* root = (tree*)malloc(sizeof(tree));
 
    char order[10];
    int val;
    int numOfOrder;
 
    cin >> numOfOrder;
    cin >> order;
    cin >> val;
 
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
     
 
    for(int i = 0; i <  numOfOrder - 1; i++){
        cin >> order;
        if(order[0] == 'i'){
            cin >> val;
            insert(val, root);
        }else if(order[0] == 'p'){
            printInorder(root);
            cout << endl;
            printPreorder(root);
            cout << endl;
        }else{
            cin >> val;
            find(val,root);
        }
    }
 
 
    return 0;
 
}
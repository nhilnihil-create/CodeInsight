#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define  all(x) (x).begin(),(x).end()
typedef long long ll;

typedef struct Node{
    ll key;
    Node *parent, *left, *right;
} Node;

Node* newNode(ll key){
    Node *newN = (Node *)malloc(sizeof(Node));
    newN->key = key;
    newN->parent = NULL;
    newN->left = NULL;
    newN->right = NULL;
    return newN;
}

Node* insert(Node *n, Node *z){
    Node *y = NULL;
    Node *x = n;
    while(x != NULL){
        y = x;
        if (z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NULL){
        n = z;
    }else if(z->key < y->key){
        y->left = z;
    }else {
        y->right = z;
    }
    return n;
}

void inorder(Node *n){
    if(n != NULL){
        inorder(n->left);
        cout << " " << n->key;
        inorder(n->right);
    }
}

void preorder(Node *n){
    if(n != NULL){
        cout << " " << n->key;
        preorder(n->left);
        preorder(n->right);
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    Node *root = NULL;
    rep(i,n){
        string o;
        cin >> o;
        if (o == "insert"){
            ll key;
            cin >> key;
            Node *newN = newNode(key);
            root = insert(root, newN);
        } else{
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
}

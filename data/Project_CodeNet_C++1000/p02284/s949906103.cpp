#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(int i = 1; i <= (int)(n); i++)
const long long INF = 1LL << 60;
const double PI=3.14159265358979323846;

struct Node{
    int key;
    Node *parent,*left,*right;
};

Node *root,*NIL;  //メモ：初期アドレスは0

void insert(int k){
    Node *x = root;
    Node *y = NIL;
    Node *z;

    z = (Node *)malloc(sizeof(Node)); //メモ：メモリを確保するとアドレスが与えられる
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){  //メモ：xにアドレスが与えられているかどうか、すなわち、二分木が空かどうか、または、挿入前の節にたどり着いたかどうか。
        y=x;
        if(z->key < x->key){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    z->parent = y;
    if(y == NIL)
        root = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

void inorder(Node *u){
    if(u == NIL) return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL)return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}
    
Node * find(Node *u,int k){
    while(u != NIL && u->key != k){
        if(k < u->key){
            u=u->left;
        }
        else{
            u=u->right;
        }
    }
    return u;
}




int main() 
{
    int n;
    string com;
    cin >> n;
    rep(i,n){
      	cin >> com;
        if(com == "insert"){
            int x;
            cin >> x;
            insert(x);
        }
        else if(com == "print"){
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
        if(com[0] == 'f'){
            int y;
            cin >> y;
            if(find(root,y) != NIL)cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}

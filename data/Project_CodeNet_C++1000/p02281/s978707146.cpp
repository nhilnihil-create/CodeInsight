#include <iostream>

#define MAX 100005
#define NIL -1

using namespace std;

struct Node
{
    int parent;
    int depth;
    int height;
    int left;
    int right;
};

struct Node T[MAX];
int n;

void setDepth(int u, int d){
    if(u==NIL) return;
    T[u].depth = d;
    if(T[u].right != NIL) setDepth(T[u].right, d+1);
    if(T[u].left != NIL) setDepth(T[u].left, d+1);
}

int setHeight(int u){
    int h1=0, h2=0;
    if(T[u].right != NIL) h1 = setHeight(T[u].right)+1;
    if(T[u].left != NIL) h2 = setHeight(T[u].left)+1;
    return T[u].height = (h1>h2 ? h1:h2);
}

int getSibling(int u){
    if(T[u].parent == NIL) return NIL;
    if(T[T[u].parent].left!=u && T[T[u].parent].left != NIL) return T[T[u].parent].left;
    if(T[T[u].parent].right!=u && T[T[u].parent].right != NIL) return T[T[u].parent].right;
    return NIL;
}

void preOrder(int u){
    if(u == NIL) return;
    cout << " " << u;
    preOrder(T[u].left);
    preOrder(T[u].right);
}

void inOrder(int u){
    if(u == NIL) return;
    inOrder(T[u].left);
    cout << " " << u;
    inOrder(T[u].right);
}

void postOrder(int u){
    if(u == NIL) return;
    postOrder(T[u].left);
    postOrder(T[u].right);
    cout << " " << u;
}

void printNode(int u){
    int i,c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    int deg = 0;
    if(T[u].left != NIL) deg++;
    if(T[u].right != NIL) deg++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << T[u].depth << ", ";
    cout << "height = " << T[u].height << ", ";

    if(T[u].parent == NIL) cout << "root" << endl;
    else  if(T[u].left == NIL && T[u].right == NIL) cout << "leaf" << endl;
    else cout << "internal node" << endl;



}

int main(){
    int v,l,r,root=0;
    cin >> n;
    for(int i=0; i<n; ++i) T[i].parent = NIL;

    for(int i=0; i<n; ++i){
        cin >> v >> l >> r;
        T[v].left = l;
        T[v].right = r;
        if( l != NIL) T[l].parent = v;
        if( r != NIL) T[r].parent = v;
    }

    for(int i = 0; i<n;++i){
        if(T[i].parent == NIL) root = i;
    }

    cout << "Preorder" << endl;
    preOrder(root);
    cout << endl;
    cout << "Inorder" << endl;
    inOrder(root);
    cout << endl;
    cout << "Postorder" << endl;
    postOrder(root);
    cout << endl;

    return 0;

}

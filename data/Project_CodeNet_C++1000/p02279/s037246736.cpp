#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {int parent, left, right;};

Node T[MAX];
int n, D[MAX];
// D[u]: the depth of u

void setDepth(int u, int p){
    // u is a node
    // p is a depth
    D[u] = p;
    if (T[u].left != NIL){
        setDepth(T[u].left, p+1);
    }
    if (T[u].right != NIL){
        setDepth(T[u].right, p);
    }
}

void printAll(int u){
    int i,c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";

    if( T[u].parent == NIL){
        cout << "root, ";
    }
    else if( T[u].left == NIL ){
        cout << "leaf, ";
    }
    else{
        cout << "internal node, ";
    }

    cout << "[";

    for (i = 0, c = T[u].left; c != NIL ; ++i, c = T[c].right)
    {
        if(i){
            cout << ", ";
        }
        cout << c;
    }
    cout << "]" << endl;
}

int main(){
    int i,j,d,v,c,l,r;
    // n: # of nodes
    cin >> n;

    // initialization
    for (int i = 0; i < n; ++i)
    {
        T[i].parent = T[i].left = T[i].right = NIL;
    }
    for (int i = 0; i < n; ++i)
    {
        // v:id, d:degree of v
        cin >> v >> d;
        // set the children of v
        for (int j = 0; j < d; ++j)
        {
            cin >> c;
            // If j = 0, the current node is the first child of v
            if(j==0){
                T[v].left = c;
            }
            else{
                T[l].right = c;
            }
            l = c;
            T[c].parent = v;
        }
    }

    // r: root
    for (int i = 0; i < n; ++i)
    {
        if (T[i].parent == NIL)
        {
            r = i;
        }
    }

    setDepth(r, 0);

    for (int i = 0; i < n; ++i)
    {
        printAll(i);
    }

    return 0;

}
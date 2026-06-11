#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 100005;
#define NIL -1

struct node{
    int parent;
    int left;
    int right;
};

node T[maxn];
int D[maxn], n;

void rec(int node, int depth){
    D[node] = depth;
    if(T[node].left != NIL)
        rec(T[node].left, depth+1);
    if(T[node].right != NIL)
        rec(T[node].right, depth);
}

void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";

    if(T[u].parent == NIL)  cout << "root, ";
    else if(T[u].left == NIL)   cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    for(int i = 0, child = T[u].left; child != NIL; i++, child = T[child].right){
        if(i)   cout << ", ";
        cout << child;
    }
    cout << "]" << endl;
}

int main(){
    int v,k,child,sib,root;
    cin >> n;
    for(int i = 0; i < n; i++)
        T[i].parent = T[i].left = T[i].right = NIL;

    for(int i = 0; i < n; i++){
        cin >> v >> k;
        for(int j = 0; j < k; j++){
            cin >> child;
            if(j == 0)  T[v].left = child;
            else    T[sib].right = child;

            sib = child;
            T[child].parent = v;
        }
    }

    for(int i = 0; i < n; i++){
        if(T[i].parent == NIL)
            root = i;
    }

    rec(root,0);
    for(int i = 0; i < n; i++)  print(i);
}


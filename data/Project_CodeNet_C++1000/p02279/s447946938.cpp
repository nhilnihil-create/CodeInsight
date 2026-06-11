#include <iostream>
#include <vector>
#define NIL -1
#define rep(i,a) for(i=0;i<a;i++)
using namespace std;

typedef struct{
    int parent;
    int left;
    int right;
    int depth;
}tree;

void rec(vector<tree> &T, int p, int q){
    T[p].depth = q;
    if(T[p].right != NIL) rec(T,T[p].right,q);
    if(T[p].left != NIL) rec(T,T[p].left,q+1);

}

void print(vector<tree> &T, int p){
    int i=0,c;

    cout << "node " << p << ": ";
    cout << "parent = " << T[p].parent << ", ";
    cout << "depth = " << T[p].depth << ", ";
    if(T[p].parent == NIL) cout << "root, ";
    else if(T[p].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";
    cout << "[";
    for(c = T[p].left; c != NIL; c = T[c].right,i++){
        if(i) cout << ", ";
        cout <<  c;
    }
    cout << "]" << endl;
}

int main(void){
    int i,j,v,d,c,l,r,n;

    cin >> n;
    vector<tree> T(n);
    rep(i,n){
        T[i].parent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }
    rep(i,n){
        cin >> v >> d;
        rep(j,d){
            cin >> c;
            if(j==0) T[v].left = c;
            else T[l].right = c;
            l = c;
            T[c].parent = v;
        }
    }
    rep(i,n){
        if(T[i].parent == NIL) r = i;
    }

    rec(T,r,0);

    rep(i,n){
        print(T,i);
    }
    return 0;
}
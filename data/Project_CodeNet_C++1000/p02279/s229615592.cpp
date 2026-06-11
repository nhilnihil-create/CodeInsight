#include<iostream>
using namespace std;

#define MAX 100005
#define NIL -1

class Node{
    public:
    int p,l,r,d;
};

Node T[MAX];
int n;

void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << T[u].d << ", ";

    if(T[u].p == NIL) cout << "root, ";
    else if(T[u].l == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    int i,c;
    for(i = 0, c = T[u].l;c != NIL;i++, c = T[c].r){
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int rec(int u,int p){
    T[u].d = p;
    if(T[u].r != NIL) rec(T[u].r,p);
    if(T[u].l != NIL) rec(T[u].l,p+1);
}

int main(int argc, char const *argv[])
{
    int v,d,l,r,c;
    cin >> n;

    for(int i = 0;i < n;i++) T[i].p = T[i].l = T[i].r = T[i].d = NIL;

    for(int i = 0;i < n;i++){
        cin >> v >> d;

        for(int j = 0;j < d;j++){
            cin >> c;
            if(j == 0) T[v].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }

    for(int i = 0;i < n;i++){
        if(T[i].p == NIL) r = i;
    }

    rec(r,0);

    for(int i = 0;i < n;i++) print(i);

    return 0;
}


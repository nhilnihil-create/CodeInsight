#include <iostream>
#define MAX 100000
#define NIL -1

using namespace std;

typedef struct{
    int parent;
    int left;
    int right;
}Node;

Node T[MAX];
int Depth[MAX];

int setDepth(int u, int d){
    Depth[u] = d;
    if(T[u].right != NIL) setDepth(T[u].right, d);
    if(T[u].left != NIL) setDepth(T[u].left, d + 1);
}

void print(int u){
    cout << "node " << u << ": parent = " << T[u].parent << ", depth = " << Depth[u] << ", ";
    if(T[u].parent == NIL) cout << "root, ";
    else if(T[u].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";
    int c = T[u].left;
    cout << "[";
    for(int i = 0, c = T[u].left; c != NIL; i++, c = T[c].right){
        if(i != 0) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int main(){
    int n, id, k, c, x, i, j;
    cin >> n;
    for(i = 0; i < n; i++){
        T[i].parent = NIL;
        T[i].left = NIL;
        T[i].right = NIL;
    }
    for(i = 0; i < n ; i++){
        cin >> id >> k;
        for(j = 0; j < k; j++){
            cin >> c;
            if(j == 0) T[id].left = c;
            else T[x].right = c;
            x = c;
            T[c].parent = id;
        }
    }
    for(i = 0; i < n; i++){
        if(T[i].parent == NIL) x = i;
    }
    setDepth(x, 0);

    for(i = 0; i < n; i++) print(i);

    return 0;
}

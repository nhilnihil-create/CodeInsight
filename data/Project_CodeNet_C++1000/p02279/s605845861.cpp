#include <iostream>
#define NIL -1
using namespace std;

struct Node {
    int parent;
    int child;
    int bro;
    int kk;
};

void get_depth(Node T[], int depth[], int u, int p);
void get_children(Node T[], int children[], int i);

int main(){
    int n;
    cin >> n;
    Node T[n];
    int depth[n];
    int children[n];
    for (int i = 0; i < n; i++){
        T[i].parent = NIL;
        T[i].child = NIL;
        T[i].bro = NIL;
    }
    int id, k;
    for (int i = 0; i < n; i++){
        cin >> id >> k;
        T[id].kk = k;
        int c[k];
        for (int j = 0; j < k; j++) {
            cin >> c[j];
            T[c[j]].parent = id;
            if (j)
                T[c[j - 1]].bro = c[j];
            else
                T[id].child = c[j];
        }
    }
    int r;
    for (int i = 0; i < n; i++){
        if (T[i].parent == NIL)
            r = i;
    }
    get_depth(T, depth, r, 0);
    for (int i = 0; i < n; i++){
        cout << "node " << i << ": parent = ";
        cout << T[i].parent << ", depth = ";
        cout << depth[i] << ", ";
        if (T[i].parent == NIL)
            cout << "root, [";
        else if (T[i].child == NIL)
            cout << "leaf, [";
        else
            cout << "internal node, [";
        if (T[i].child == NIL)
            cout << ']' << endl;
        else {
            get_children(T, children, i);
            for (int j = 0; j < T[i].kk - 1; j++) {
                cout << children[j] << ", ";
            }
            cout << children[T[i].kk - 1] << ']' << endl;
        }
    }
    return 0;
}

void get_depth(Node T[],int depth[], int u,int p){
    depth[u] = p;
    if (T[u].bro != NIL)
        get_depth(T, depth, T[u].bro, p);
    if (T[u].child != NIL)
        get_depth(T, depth, T[u].child, p + 1);
}

void get_children(Node T[], int children[], int i){
    int cnt = 0;
    int c = T[i].child;
    children[cnt] = c;
    while (T[c].bro != NIL){
        cnt++;
        children[cnt] = T[c].bro;
        c = T[c].bro;
    }
}

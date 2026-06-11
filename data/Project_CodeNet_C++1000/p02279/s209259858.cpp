#include <iostream>
using namespace std;

#define MAX 1000000

struct Node {
    int parent, left, right;
};

struct Node T[MAX];
int D[MAX];
int get_depth(int);
void setDepth(int, int);

int main() {
    int n;
    int n2;
    int n3;
    int node;

    cin >> n;
    for (int i = 0; i < n; i++) { T[i].parent = T[i].left = T[i].right = -1;}
    
    for (int i = 0; i < n; i++) {
        int prev_node = -1;
        cin >> n2 >> n3;
        //cout << "n2: " << n2 << ", n3:" << n3 << endl;
        for (int i2 = 0; i2 < n3; i2++) {
            cin >> node;
            if (i2 == 0) T[n2].left = node;
            T[node].parent = n2;
            if (prev_node != -1) T[prev_node].right = node;
            prev_node = node; 
        }
    }

    //for (int i = 0; i < n; i++){
    //    cout << "Node:" << i << ", " << T[i].parent << ", " << T[i].left << ", " << T[i].right << ", " << endl;
    //}
    //
    int r;
    for (int i = 0; i < n; i++){
        if (T[i].parent == -1) r = i;
    }

    setDepth(r, 0);
    int c;
    int a[100];
    int parent;
    for (int i = 0; i < n; i++){
        cout << "node " << i << ": parent = " << T[i].parent << ", depth = " ;
        //cout << get_depth(i) << ", " ;
        cout << D[i] << ", " ;
        c = T[i].left;
        int depth = 0;
        if (T[i].parent == -1) cout << "root, " ;
        else if (T[i].left == -1) cout << "leaf, ";
        else cout << "internal node, ";
        cout << "[";
        int is_first = -1;
        while (c != -1) {
         if (is_first != -1) cout << ", ";
         cout << c;
        c = T[c].right;
        is_first = 1;
        }
        cout << "]";
        cout << endl;
    }
    return 0;

}

int get_depth(int node_id){
    int depth = 0;
    int c;
    c = T[node_id].parent;
        
    while (c != -1) {
        depth++;
        c = T[c].parent;
    }
    return depth;
}

int p;
int u;
void setDepth(int u, int p) {
    D[u] = p;
        if (T[u].right != -1)
            setDepth(T[u].right, p);
        if (T[u].left != -1)
            setDepth(T[u].left, p + 1);
}
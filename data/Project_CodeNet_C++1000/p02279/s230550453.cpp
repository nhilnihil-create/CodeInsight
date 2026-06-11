#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1
struct Node 
{
    int parent, left, right;
};

Node node[MAX];
int n, depth[MAX];



void print(int u)
{
    int i, c;
    
    cout << "node " << u << ": ";
    cout << "parent = " << node[u].parent << ", ";
    cout << "depth = " << depth[u] << ", ";
    if (node[u].parent == NIL){
        cout << "root, ";
    } else if (node[u].left == NIL){
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }
    cout << "[";

    for (i = 0, c = node[u].left; c != NIL; i++, c = node[c].right) {
        if (i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}


void getDepth (int u, int p)
{
    depth[u] = p;
    if ( node[u].right != NIL ){
        getDepth(node[u].right, p);
    }
    if ( node[u].left != NIL ){
        getDepth(node[u].left, p + 1);
    }
    
    
}

int main()
{
    int id, degree, child, first_child, root;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        node[i].parent = node[i].left = node[i].right = NIL;
    }

    for (int i = 0; i < n; i++){
        cin >> id >> degree;
        for (int j = 0; j < degree; j++){
            cin >> child;
            if (j == 0){
                node[id].left = child;
            } else {
                node[first_child].right = child;
            }
            first_child = child;
            node[child].parent = id;
        }
    }
    for (int i = 0; i < n; i++){
        if (node[i].parent == NIL){
            root = i;
        }
    }

    getDepth(root, 0);
    for (int i = 0; i < n; i++){
        print(i);
    }
    return 0;
}
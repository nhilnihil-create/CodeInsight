#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node{int parent, left, right;};

Node Tree[MAX];
int n, Depth[MAX];

void print(int index){
    int i, child;
    cout << "node " << index << ": ";
    cout << "parent = " << Tree[index].parent << ", ";
    cout << "depth = " <<  Depth[index] << ", ";

    if(Tree[index].parent == NIL) cout << "root, ";
    else if(Tree[index].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";
    for(i=0, child=Tree[index].left; child != NIL; i++, child = Tree[child].right){
        if(i) cout << ", ";
        cout << child;
    }
    cout << "]" << endl;
}

void setDepth(int index, int currentDepth){
    Depth[index] = currentDepth;
    if(Tree[index].right != NIL) setDepth(Tree[index].right, currentDepth);
    if(Tree[index].left != NIL) setDepth(Tree[index].left, currentDepth+1);
}

int main(void){
    int d, vertex, in, left, right;
    cin >> n;
    for(int i=0;i<n;i++) Tree[i].parent = Tree[i].left = Tree[i].right = NIL;

    for(int i=0;i<n;i++){
        cin >> vertex >> d;
        for(int j=0;j<d;j++){
            cin >> in;
            if(j==0) Tree[vertex].left = in;
            else Tree[left].right = in;
            left = in;
            Tree[in].parent = vertex;
        }
    }

    for(int i=0;i<n;i++)
        if(Tree[i].parent == NIL) right=i;
    setDepth(right, 0);

    for(int i=0;i<n;i++) print(i);

    return 0;
}

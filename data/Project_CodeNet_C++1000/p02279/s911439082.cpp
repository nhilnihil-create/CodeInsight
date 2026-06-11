#include <bits/stdc++.h>
using namespace std;

const int nil = -1;
const int MAX = 100001;

struct Node{int parent,left_child,right_brother;};
Node node_array[MAX];
int depth_array[MAX];

void set_depth(int node_number,int depth){
    depth_array[node_number] = depth;
    int r = node_array[node_number].right_brother;
    if(r != nil){
        set_depth(r,depth);
    }
    int l = node_array[node_number].left_child;
    if(l != nil){
        set_depth(l,depth+1);
    }
}

void print(int n){
    int i,c;
    cout << "node " << n << ": ";
    cout << "parent = " << node_array[n].parent << ", ";
    cout << "depth = " << depth_array[n] << ", ";
    
    if(node_array[n].parent == -1) cout << "root, ";
    else if(node_array[n].left_child == -1) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";
    for(i=0,c = node_array[n].left_child; c != -1;i++, c = node_array[c].right_brother){
        if (i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        node_array[i].left_child = node_array[i].parent = node_array[i].right_brother = nil;
    }
    for(int i=0;i<n;i++){
        int node_number,deg;
        cin >> node_number >> deg;
        int left;
        for(int j=0;j<deg;j++){
            int c;
            cin >> c;
            if(j == 0){
                node_array[node_number].left_child = c;
            }else{
                node_array[left].right_brother = c;
            }
            left = c;
            node_array[c].parent = node_number;
        }
    }
    int root;
    for(int i=0;i<n;i++){
        if(node_array[i].parent == nil){
            root = i;
        }
    }

    set_depth(root,0);
    for(int i=0;i<n;i++){
        print(i);
    }
}



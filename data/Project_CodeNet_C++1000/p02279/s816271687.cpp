#include <bits/stdc++.h>
using namespace std;

struct Node{
    int parent,left_child,right_brother;
};

int nil = -1;
Node node[100005];
int depth[100005];

void print_tree(int id){
    cout << "node " << id;
    cout <<": parent = " << node[id].parent;
    cout << ", depth = " << depth[id];
    cout << ", ";
    if(node[id].parent == nil)cout << "root";
    else if(node[id].left_child == nil)cout << "leaf";
    else cout << "internal node";
    cout << ", [";
    int child = node[id].left_child;
    while(child != nil){
        cout << child;
        child = node[child].right_brother;
        if(child != nil){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void depth_check(int id,int p){
    depth[id] = p;
    if(node[id].right_brother!=nil) depth_check(node[id].right_brother,p);
    if(node[id].left_child!=nil) depth_check(node[id].left_child,p+1);
    return;
}

int main(){
    int N,M;
    int id,c;
    cin >> N;
    /*木の初期化*/
    for(int i=0;i<N;i++){
        node[i].parent = node[i].left_child = node[i].right_brother = nil;
    }

    int right,root;
    for(int i=0;i<N;i++){
        cin >> id >> M;
        for(int j=0;j<M;j++){
            cin >> c;
            if(j == 0)node[id].left_child = c;
            else node[right].right_brother = c;
            right = c;
            node[c].parent = id;
        }
    }

    for(int j=0;j<N;j++){
        if(node[j].parent == nil)root = j;
    }

    depth_check(root,0);

    for(int i=0;i<N;i++){
        print_tree(i);
    }

    return 0;
}

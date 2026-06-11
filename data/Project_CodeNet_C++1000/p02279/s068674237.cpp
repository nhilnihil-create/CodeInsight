#include <iostream>
using namespace std;
struct T{
    int parent,children,depth,right;
};
void maketree(T tree[]){
    int node,k,m,tmp;
    cin>>node>>k;
    for(int j=0;j<k;j++){
        cin>>m;
        if(j==0){
            tree[node].children=m;
        }
        else{
            tree[tmp].right=m;
        }
        tmp=m;
        tree[m].parent=node;
        tree[m].depth=tree[node].depth+1;
    }
}
void depth(int root,T tree[]){
    int l=tree[root].children;
   if(tree[l].children!=-1 && l!=-1){
        depth(l,tree);
    }
    if(l!=-1){
        tree[l].depth=tree[root].depth+1;
        while(tree[l].right!=-1){
            tree[tree[l].right].depth=tree[l].depth;
            l = tree[l].right;
        }
    }
}
int main(){
    T tree[100000];
    int n,root=0;
    cin>>n;
    for(int i=0;i<n;i++){
        tree[i].depth=0;
        tree[i].parent=-1;
        tree[i].children=-1;
        tree[i].right=-1;
    }
    for(int i=0;i<n;i++){
        maketree(tree);
    }
    while(tree[root].parent!=-1){
        root=tree[root].parent;
    }
    depth(root,tree);
    for(int i=0;i<n;i++){
        cout<<"node "<<i<<": parent = "<<tree[i].parent<<", depth = "<<tree[i].depth;
        if(tree[i].depth==0){
            cout<<", root, [";
        }
        else if(tree[i].children==-1){
            cout<<", leaf, [";
        }
        else{
            cout<<", internal node, [";
        }
        if(tree[i].children!=-1){
            cout<<tree[i].children;
        }
        int l=tree[i].children;
        while(tree[l].right!=-1 && tree[i].children!=-1){
            cout<<','<<" "<<tree[l].right;
            l=tree[l].right;
        }
        cout<<']'<<endl;
    }
    return 0;
}

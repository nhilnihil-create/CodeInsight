#include <bits/stdc++.h>
using namespace std;
struct Node{
    int parent,left,right;
    Node(){
        parent=-1;left=-1;right=-1;
    }
};

int node_depth(Node T[],int D[],int node){
    if(D[node]!=-1)return D[node];
    if(T[node].parent==-1)D[node]=0;
    else D[node]=1+node_depth(T,D,T[node].parent);
    return D[node];
}


int main(){
    int n;cin>>n;
    Node Tree[n];
    int id,k,children,prec;
    int Depth[n];
    for(int i=0;i<n;i++)Depth[i]=-1;
    for(int i=0;i<n;i++){
        scanf("%d %d",&id,&k);
        if(k>0){
            scanf("%d",&children);
            Tree[id].left=children;
            Tree[children].parent=id;
        }
        for(int j=1;j<k;j++){
            prec=children;
            scanf("%d",&children);
            Tree[prec].right=children;
            Tree[children].parent=id;
        }
    }
    for(int i=0;i<n;i++){
        printf("node %d: parent = %d, ",i,Tree[i].parent);
        printf("depth = %d, ",node_depth(Tree,Depth,i));
        if(Tree[i].parent==-1)printf("root");
        else{
            if(Tree[i].left==-1)printf("leaf");
            else printf("internal node");
        }
        printf(", [");
        int j=Tree[i].left;
        while(j!=-1){
            if(j!=Tree[i].left)printf(", ");
            printf("%d",j);
            j=Tree[j].right;
        }
        printf("]\n");
    }
}

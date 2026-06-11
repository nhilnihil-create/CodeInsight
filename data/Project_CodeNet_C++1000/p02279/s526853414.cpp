#include<bits/stdc++.h>
using namespace std;
struct Node{
    int right,left,parent;
    Node(){ right=-1;left=-1;parent=-1; }
};
int main(){
    int n;
    scanf("%d",&n);
    Node tree[n];
    int id,k,c;
    for(int i=0;i<n;++i){
        scanf("%d%d",&id,&k);
        if(k){ scanf("%d",&c); tree[id].left=c; tree[c].parent=id; }
        for(int j=1;j<k;++j){
            id=c;
            scanf("%d",&c);
            while(~tree[id].right) id=tree[id].right;
            tree[id].right=c;
            tree[c].parent=tree[id].parent;
        }
    }
    for(int i=0;i<n;++i){
        int depth=0;
        int pare=tree[i].parent;
        while(pare!=-1){
            depth++;
            pare=tree[pare].parent;
        }
        printf("node %d: parent = %d, depth = %d, %s, [",i,tree[i].parent,depth,tree[i].parent==-1?"root":tree[i].left!=-1?"internal node":"leaf");
        int child=tree[i].left;
        if(~child){
            printf("%d",child);
            while(tree[child].right!=-1){
                printf(", %d",tree[child].right);
                child=tree[child].right;
            }
        }
        printf("]\n");
    }
    return 0;
}
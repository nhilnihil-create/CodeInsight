#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define NIL -1
int n, D[MAX];

struct node{
    int p, l, r;
};
node T[MAX];

void printTree(){
    for(int i=0;i<n;++i){
        printf("node %d: parent = %d, depth = %d, ",i,T[i].p,D[i]);
        if(T[i].p == NIL) printf("root, [");
        else{
            if(T[i].l == NIL) printf("leaf, [");
            else printf("internal node, [");
        }
        for(int j=T[i].l;j != NIL;){
            printf("%d",j);
            j = T[j].r;
            if(j != NIL){
                printf(", ");
            }
            else break;
        }
        printf("]\n");
    }
}


void recDepth(int pos, int depth){
    D[pos] = depth;
    if(T[pos].l != NIL){
        recDepth(T[pos].l,depth+1);
    }
    if(T[pos].r != NIL){
        recDepth(T[pos].r,depth);
    }
}

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;++i){
        T[i].l = T[i].p = T[i].r = NIL;
        D[i] = 0;
    }
    int id, num_child, child_id, sib, root;

    for(int i=0;i<n;++i){
        cin >> id >> num_child;
        for(int j=0;j<num_child;++j){
            cin >> child_id;
            if(j==0) T[id].l = child_id;
            else T[sib].r = child_id;
            sib = child_id;
            T[child_id].p = id;
        }
    }
    for(int i=0;i<n;++i){
        if(T[i].p==NIL) root=i;
    }
    recDepth(root,0);
    printTree();
    return 0;
}


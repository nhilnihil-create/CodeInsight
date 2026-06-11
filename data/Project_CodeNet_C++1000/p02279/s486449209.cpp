#include <cstdio>
#include <cstdlib>

typedef struct{
    int p;
    int b;
    int s;
    int d;
}node;

void calcDepth(node* nd,int id, int d){
    if(id<0)return;
    nd[id].d = d;
    calcDepth(nd,nd[id].b,d);
    calcDepth(nd,nd[id].s,d+1);
}

int main(){
    int i,j,n,id,k,tmp,c,forp;
    forp = 0;
    scanf("%d",&n);
    node* nd = (node*)malloc(sizeof(node)*n);
    for(i=0;i<n;i++){
        nd[i].p = -1;
        nd[i].b = -1;
        nd[i].s = -1;
        nd[i].b = -1;
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&id,&k);
        if(k>0){
            scanf("%d",&c);
            nd[id].s = c;
            tmp = c;
            forp += tmp;
            for(j=0;j<k-1;j++){
                scanf("%d",&c);
                nd[tmp].p = id;
                nd[tmp].b = c;
                tmp = c;
                forp += tmp;
            }
            nd[tmp].p = id;
        }
    }
    int rootid = (n*(n-1)) / 2 - forp;
    calcDepth(nd,rootid,0);
    for(i=0;i<n;i++){
        printf("node %d: parent = %d, depth = %d,",i,nd[i].p,nd[i].d);
        if(nd[i].p<0)printf(" root,");
        else if(nd[i].s<0)printf(" leaf,");
        else printf(" internal node,");
        printf(" [");
        tmp = nd[i].s;
        if(tmp>=0){
            printf("%d",tmp);
            while(nd[tmp].b>=0){
                tmp = nd[tmp].b;
                printf(", %d",tmp);
            }
        }
        printf("]\n");
    }
    return 0;
}


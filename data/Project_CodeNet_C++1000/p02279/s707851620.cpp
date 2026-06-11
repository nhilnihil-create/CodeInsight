#include<stdio.h>
using namespace std;
#define NEL -1

struct tree{
    int p,l,r;
};

tree a[100005];
int d[100005];

int re(int u,int p){
    d[u]=p;
    if(a[u].r>=0) re(a[u].r,p);
    if(a[u].l>=0) re(a[u].l,p+1);
}

void print(int n){
    for(int i=0;i<n;i++){
        printf("node %d:",i);
        printf(" parent = %d, ",a[i].p);
        printf("depth = %d, ",d[i]);
        if(a[i].p==NEL) printf("root, ");
        else{
            if(a[i].l==NEL) printf("leaf, ");
            else printf("internal node, ");
        }
        printf("[");
        int c=a[i].l;
        while(c>=0){
            if(c==a[i].l)
                printf("%d",c);
            else
                printf(", %d",c);
            c=a[c].r;
        }
        printf("]");
        printf("\n");
    }
}

int main(){
    int n,id,k,m,c;
    int l;
    scanf("%d",&n);
    for(int i=0;i<n;i++) { a[i].p=NEL; a[i].l=NEL; a[i].r=NEL; }
    for(int i=0;i<n;i++){
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&m);
            a[m].p=id;
            if(!j) a[id].l=m;
            else a[l].r=m;
            l=m;
            }
    }
    for(int i=0;i<n;i++){
        if(a[i].p==NEL){
            c=i;
            break;
        }
    }
    re(c,0);
    print(n);
    return 0;
}
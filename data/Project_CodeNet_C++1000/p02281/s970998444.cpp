#include <cstdio>
#define maxn 10000
#define NIL -1

struct Node{
    int p,l,r;
}T[maxn];

int n;

void preorder(int u){
    if(u==NIL) return;
    printf(" %d",u);
    preorder(T[u].l);
    preorder(T[u].r);
}


void inorder(int u){
    if(u==NIL) return;
    inorder(T[u].l);
    printf(" %d",u);
    inorder(T[u].r);
}


void postorder(int u){
    if(u==NIL) return;
    postorder(T[u].l);
    postorder(T[u].r);
    printf(" %d",u);
}


int main(){
   // freopen("data.in","r",stdin);
    int v,l,r,root;

    scanf("%d",&n);
    for(int i=0;i<n;i++) T[i].p=NIL;

    for(int i=0;i<n;i++){
        scanf("%d %d %d",&v,&l,&r);
        T[v].l=l;
        T[v].r=r;
        if(l!=NIL) T[l].p=v;
        if(r!=NIL) T[r].p=v;
    }


    for(int i=0;i<n;i++) if(T[i].p==NIL) root=i;

    printf("Preorder\n");
    preorder(root);
    printf("\n");
    printf("Inorder\n");
    inorder(root);
    printf("\n");
    printf("Postorder\n");
    postorder(root);
    printf("\n");
    return 0;
}
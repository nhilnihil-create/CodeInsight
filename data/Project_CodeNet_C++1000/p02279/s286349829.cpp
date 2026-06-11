#include<cstdio>
#define nil -1
struct shu{
int left;
int  parent;
int right;
};
int d[100005];
shu a[100005];
void shendu(int u,int p){
d[u]=p;
if(a[u].right!=nil)shendu(a[u].right,p);
if(a[u].left!=nil)shendu(a[u].left,p+1);
}
void shuchu(int u){
printf("node %d: ",u);
printf("parent = %d, ",a[u].parent);
printf("depth = %d, ",d[u]);
if(a[u].parent==nil)printf("root, ");
else if(a[u].left==nil)printf("leaf, ");
else  printf("internal node, ");
printf("[");
int c;
for(int i=0,c=a[u].left;c!=nil;i++,c=a[c].right){
    if(i)printf(", ");
    printf("%d",c);
}
printf("]");
}
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
    a[i].left=a[i].right=a[i].parent=nil;
}
int d,k,m;
int l=0;
for(int i=0;i<n;i++){
    scanf("%d%d",&d,&k);
    for(int j=0;j<k;j++){
        scanf("%d",&m);
        if(j==0)a[d].left=m;
        else a[l].right=m;
        l=m;
        a[m].parent=d;
    }
}
int x;
for(int i=0;i<n;i++){
    if(a[i].parent==nil)x=i;
}
shendu(x,0);
for(int i=0;i<n;i++){
    shuchu(i);
    printf("\n");
}
return 0;
}
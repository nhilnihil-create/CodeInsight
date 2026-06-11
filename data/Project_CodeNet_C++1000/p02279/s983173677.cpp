#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef struct{
  int parent,child,brother;
}node;
node tree[100001];
int depth(int x,int sum);
int children(int x);
int main(){
  int n;
  memset(tree,-1,sizeof(tree));
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int id,k;
    scanf("%d%d",&id,&k);
    if(k>0){
      scanf("%d",&tree[id].child);
      int p=tree[id].child;
      tree[p].parent=id;
      for(int j=0;j<k-1;j++){
	scanf("%d",&tree[p].brother);
	p=tree[p].brother;
	tree[p].parent=id;
      }
    }
  }
  for(int i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,tree[i].parent);
    printf("depth = %d, ",depth(tree[i].parent,0));
    if(tree[i].parent==-1) printf("root, ");
    else if(tree[i].child==-1) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    if(tree[i].child==-1) printf("]\n");
    else{
      printf("%d",tree[i].child);
      int p=tree[i].child;
      children(tree[p].brother);
      printf("]\n");
    }
  }
    return 0;
}
int depth(int x,int sum){
  if(x==-1) return sum;
  return depth(tree[x].parent,sum+1);
}
int children(int x){
  if(x==-1) return 0;
  else{
    printf(", %d",x);
    return children(tree[x].brother);
  }
}
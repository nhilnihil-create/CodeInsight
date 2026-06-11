#include <stdio.h>
#include <stdlib.h>
#define N 1000000
 
typedef struct node{
  int p;
  int right;
  int left;
}Node;
 
 
int main(){
   
  int n,i,j,l,c,k,id,P,depth,r;
  Node a[N],tmp;
   
  scanf("%d",&n);
   
  for(i=0;i<n;i++){
    a[i].p = -1;
    a[i].right = -1;
    a[i].left = -1;
  }
   
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
     
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0) a[id].left = c;
      else a[r].right = c;
      a[c].p = id;
      r=c;
    }
  }
   
  for(i=0;i<n;i++){
    depth = 0;
    P = a[i].p;
     
    while(P != -1){
      P = a[P].p;
      depth++;
    }
     
    if(a[i].p == -1){
      printf("node %d: parent = %d, depth = %d, root, [",
       i,a[i].p,depth);
    }
    else if(a[i].left == -1) printf("node %d: parent = %d, depth = %d, leaf, [",i,a[i].p,depth);
    else printf("node %d: parent = %d, depth = %d, internal node, [",i,a[i].p,depth);
     
    P = a[i].left;
    if(P != -1) printf("%d",P);
     
    while(P != -1){
      P = a[P].right;
      if(P != -1) printf(", %d",P);
    }
    printf("]\n");
  }
 
  return 0;
}
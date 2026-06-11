#include<bits/stdc++.h>
using namespace std;
typedef struct{
  int parent;
  int left,right;
}node;
node t[100005];
int n;
int d[100005];

void get_depth(int now,int deep){
  d[now]=deep;
  
  if(t[now].left!=-1){
    get_depth(t[now].left,deep+1);
  }
  if(t[now].right!=-1){
    get_depth(t[now].right,deep);
  }

  return;
}

main()
{
  for(int i=0;i<100005;i++){
    t[i].parent=-1;
    t[i].left=-1;
    t[i].right=-1;
  }
  
  int id;
  int a,b;
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&a);
    
    if(a!=0){
      scanf("%d",&b);
      t[id].left=b;
      t[b].parent=id;
      int l=b;
      
      for(int i=0;i<a-1;i++){
        scanf("%d",&b);
        t[l].right=b;
        t[b].parent=id;
        l=b;
      }
    }
  }

  int root;
  for(int i=0;i<n;i++){
    if(t[i].parent==-1)
      root=i;
  }
  get_depth(root,0);
  
  for(int i=0;i<n;i++){
    
    printf("node %d: parent = %d, depth = %d",i,t[i].parent,d[i]);
    
    if(t[i].parent==-1)
      printf(", root");
    if(t[i].parent!=-1&&t[i].left!=-1)
      printf(", internal node");
    if(t[i].parent!=-1&&t[i].left==-1)
      printf(", leaf");

    printf(", [");
    int p=t[i].left;
    while(p!=-1){
      printf("%d",p);
      p=t[p].right;
      if(p!=-1)
        printf(", ");
    }
    printf("]");

    printf("\n");
  }
  return (0);
}
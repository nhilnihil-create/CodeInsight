#include<iostream>
#include<cstdlib>
#include<cstdio>

#define N 100001
#define NIL -1
using namespace std;

//array
int parent[N];
int leftc[N];
int rightc[N];

int degree[N];
int depth[N];
int root;


int main(){

  int n,i,j,id,child,bef;
  int flag=0;
   //initialize
  for(i=0;i<N;i++){
    parent[i]=NIL;
    leftc[i]=NIL;
    rightc[i]=NIL;
    degree[i]=0;
    depth[i]=0;
  }

  //load n
  scanf("%d",&n);

  //load data set parent, left child and 
  for(i=0;i<n;i++){
    scanf("%d %d",&id,&degree[i]);


    for(j=0;j<degree[i];j++){
      scanf("%d",&child);
  
      parent[child]=id;  
    
      if(j==0){
	leftc[id]=child;
      }
      else{
	rightc[bef]=child;
      }

      bef=child;
    }
  }

  //test
  // for(i=0;i<n;i++)printf("%d parent: %d leftchild: %d right child: %d\n",i,parent[i],leftc[i],rightc[i]);

  //find root
  for(i=0;i<n;i++){
    if(parent[i]==NIL){
      root=i;
      break;
    }
  }
  
  //calc depth

  for(i=0;i<n;i++){
    for(j=parent[i];j!=NIL;j=parent[j]){
      depth[i]++;
    }

  }
  

  
  
  //print
  for(i=0;i<n;i++){



    printf("node %d: parent = %d, depth = %d, ",i,parent[i],depth[i]);

    if(parent[i]==NIL)printf("root, ");
    else if(leftc[i]==NIL) printf("leaf, ");
    else printf("internal node, ");
   
    printf("[");
    for(j=leftc[i];j!=NIL;j=rightc[j]){
      printf("%d",j);
      if(rightc[j]!=NIL)printf(", ");
    }
    printf("]");

    printf("\n");
  }
  
  
  return 0;
}

//problem A is most difficult.
#include <cstdio>
#include <string>
#include <iostream>
#define MAX 100000
#define NIL -1


using namespace std;

struct Node{int parent,left,right;};
Node T[MAX];
int n;

void initialize(){
  for(int i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].left=NIL;
    T[i].right=NIL;
  }
}

int getdepth(int x){
  int depth=0;
  while(T[x].parent!=NIL){
    x=T[x].parent;
    depth++;
  }
  return depth;
}

string getstate(int x){
  if(T[x].parent==NIL) return "root";
  else if(T[x].left==NIL) return "leaf";
  else return "internal node";
}

void display(){
  for(int i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, %s, [",
    i,T[i].parent,getdepth(i),getstate(i).c_str());
    if(T[i].left!=NIL){
      printf("%d",T[i].left);
      int x=T[T[i].left].right;
      while(x!=NIL){
        printf(", %d",x);
        x=T[x].right;
      }
    }
    printf("%s\n","]");
  }
}

int main(){
  scanf("%d",&n);
  initialize();
  for(int i=0;i<n;i++){
    int idx,nc;
    scanf("%d %d",&idx,&nc);
    if(nc>0){
      int c[nc];
      scanf("%d",&c[0]);
      T[idx].left=c[0];
      T[c[0]].parent=idx;
      for(int i=1;i<nc;i++){
        scanf("%d",&c[i]);
        T[c[i-1]].right=c[i];
        T[c[i]].parent=idx;
      }
    }
  }
  display();
}
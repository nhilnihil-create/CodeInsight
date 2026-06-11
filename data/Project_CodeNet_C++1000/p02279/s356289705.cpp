#include <iostream>
#include <cstdio>
#include <string>

#define MAX 100001
#define NIL -1

using namespace std;

//left-child,right-sibling representation
struct Node{int parent,left,right;};

struct Node T[MAX];

int getDepth(int idx){
  int dep=0;
  while(T[idx].parent!=NIL){
    idx=T[idx].parent;
    dep++;
  }
  return dep;
}

string getState(int idx){
  if(T[idx].parent==NIL){
    return "root";
  }else if(T[idx].left==NIL){
    return "leaf";
  }else{
    return "internal node";
  }
}

int main(){
  int n; cin >> n;
  for(int i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].left=NIL;
    T[i].right=NIL;
  }
  for(int i=0;i<n;i++){
    int id,k; scanf("%d %d",&id,&k);
    if(k==0) continue;
    int x; cin >> x;
    T[x].parent=id; T[id].left=x;
    for(int i=1;i<k;i++){
      int c; scanf("%d",&c);
      T[c].parent=id;
      T[x].right=c;
      x=T[x].right;
    }
  }
  for(int i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i, T[i].parent, getDepth(i));
    cout << getState(i) << ", ";
    cout << "[";
    if(T[i].left!=NIL){
      printf("%d",T[i].left);
      int sib=T[T[i].left].right;
      while(sib!=NIL){
        printf(", %d",sib);
        sib=T[sib].right;
      }
    }
    cout << "]" << endl;
  }
}
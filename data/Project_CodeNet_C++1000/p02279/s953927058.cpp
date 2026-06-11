#include <bits/stdc++.h>
using namespace std;

#define NIL -1
#define MAX 100000

// left-child, right-sibling representation
class node{
public:
  int parent;
  int left;
  int right;
  int depth;

  node(){
    parent = NIL;
    left = NIL;
    right = NIL;
    depth = NIL;
  }
};

node T[MAX];

void setDepth(int id, int d){
  T[id].depth = d;
  if(T[id].left != NIL) setDepth(T[id].left, d+1);
  if(T[id].right != NIL) setDepth(T[id].right, d);
}

int main(){

  int n;
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    int id, k;
    scanf("%d %d",&id,&k);

    // Save info to Tree
    for(int j=0; j<k; j++){
      int c; int prev_c;
      scanf("%d",&c);
      if(j==0) T[id].left = c;
      else T[prev_c].right = c;
      T[c].parent = id;
      prev_c = c;
    }
  }

  // Find root id.
  int root;
  for(int i=0; i<n; i++){
    if(T[i].parent == NIL){
      root = i;
      break;
    }
  }

  // Calculate depth recurrently
  setDepth(root, 0);

  //print result
  for(int i=0; i<n; i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,T[i].depth);

    if(T[i].parent == NIL){
      printf("root, ");
    }
    else if(T[i].left != NIL){
      printf("internal node, ");
    }
    else{
      printf("leaf, ");
    }

    printf("[");
    for(int j=0, c = T[i].left; c != NIL; j++, c = T[c].right){
      if(j != 0) printf(", ");
      printf("%d",c);
    }
    printf("]\n");
  }

  return 0;
}


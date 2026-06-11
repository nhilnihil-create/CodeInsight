#include <stdio.h>
#define MAX 100005
#define OUT -1
struct Node{
  int p;
  int l;
  int r;
};

void depth(int,int);
void print(int);
//using namespace std;

struct Node T[MAX];
int n, A[MAX];

int main(){
  int i,j,d,v,c,l,r;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    T[i].r = OUT;
    T[i].l = T[i].r;
    T[i].p = T[i].l;
  }
  for(i = 0; i < n; i++){
    scanf("%d",&v);
    scanf("%d",&d);
    for(j = 0; j < d; j++){
      scanf("%d",&c);
    if(j == 0){
      T[v].l = c;
    }
    else{
      T[l].r = c;
    }
    l = c;
    T[c].p = v;
    }
  }
  for(i = 0; i < n; i++){
    if(T[i].p == OUT){
      r = i;
    }
  }
  depth(r,0);
  for(i = 0; i < n; i++){
    print(i);
  }
  return 0;
}// end of main func

void depth(int u, int p){
  A[u] = p;
  if(T[u].r != OUT){
    depth(T[u].r,p);
  }
  if(T[u].l != OUT){
    depth(T[u].l , p+1);
  }
}//end of depth func

void print(int u){
int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",A[u]);
  if(T[u].p == OUT){
    printf("root, ");
  }
  else if(T[u].l == OUT){
    printf("leaf, ");
  }
  else{
    printf("internal node, ");
  }
  printf("[");
  for(i = 0, c = T[u].l; c != OUT; i++, c = T[c].r){
    if(0 < i){
      printf(", ");
    }
    printf("%d",c);
  }
  printf("]\n");
}//end of print func
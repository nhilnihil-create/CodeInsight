#include<bits/stdc++.h>
using namespace std;

#define N_MAX 100001
#define NIL -1

struct node{
  int parent, sibiling, child;
};

int n;
node T[N_MAX];
int D[N_MAX];

void insert(){
  int i, j;
  int s, p, c, m, tmp_s;
  
  for(i=0; i<n; i++) T[i].parent=T[i].sibiling=T[i].child=NIL;
  
  for(i=0; i<n; i++){
    scanf("%d %d", &p, &m);

    for(j=0; j<m; j++){
      scanf("%d", &s);
      T[s].parent=p;
      
      if(j==0) T[p].child=s;
      else T[tmp_s].sibiling=s;

      tmp_s=s;	    
    }
  }  
}

void setd(int i, int d){
  D[i]=d;

  if(T[i].sibiling != NIL) setd(T[i].sibiling, d);
  if(T[i].child != NIL) setd(T[i].child, d+1);
}

void depth(){
  int i, root;
  
  for(i=0; i<n; i++){
    if(T[i].parent==NIL){
      root=i;
      break;
    }
  }

  setd(root, 0);
}

void print(int i){
  int j, s=T[i].child;
  printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, D[i]);

  if(T[i].parent==NIL){
    printf("root, [");
    for(j=0; ; j++){
      if(j==0){
	if(s==NIL) break;
	printf("%d", s);
	s=T[s].sibiling;
      }
      else{
	if(s==NIL) break;
	printf(", %d", s);
	s=T[s].sibiling;
      }
    }
    printf("]\n");
  }
  else if(T[i].child==NIL) printf("leaf, []\n");
  else{
    printf("internal node, [");
    for(j=0; ; j++){
      if(j==0){
	if(s==NIL) break;
	printf("%d", s);
	s=T[s].sibiling;
      }
      else{
	if(s==NIL) break;
	printf(", %d", s);
	s=T[s].sibiling;
      }
    }
    printf("]\n");
  }
}

int main(void){
  int i;

  scanf("%d", &n);
  insert();
  depth();
  
  for(i=0; i<n; i++) print(i);
  
  return 0;
}


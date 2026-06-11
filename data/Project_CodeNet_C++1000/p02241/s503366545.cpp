#include <bits/stdc++.h>
using namespace std;
int prim(void);

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int A[MAX][MAX];
int n;

int main(){
  int i,j,e;
  int u;
  cin >> n;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      cin >> e;
      A[i][j] = (e == -1) ? INFINITY : e;
    }
  }
  cout << prim() << endl;
  return 0;
}

int prim(){
  int sum = 0;
  int i,j,minV;
  int d[MAX],p[MAX],color[MAX];
  int u,v; 
  for(i = 0; i < n; i++){
    d[i] = INFINITY;
    p[i] = -1;
    color[i] = WHITE;
  }
  d[0] = 0;
  while(1){
    minV = INFINITY;
    u = -1;
    for(i = 0; i < n; i++){
      if(minV > d[i] && color[i] != BLACK){
        u = i;
        minV = d[i];
      }
    }
    if(u == -1){
      break;
    }
    color[u] = BLACK;
    for(v = 0; v < n; v++){
      if(color[v] != BLACK && A[u][v] != INFINITY){
        if(d[v] > A[u][v]){
          d[v] = A[u][v];
          p[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
  //sum = 0;
  for(i = 0; i < n; i++){
    if(p[i] != -1){
      sum += A[i][p[i]];
    }
  }
  return sum;
}
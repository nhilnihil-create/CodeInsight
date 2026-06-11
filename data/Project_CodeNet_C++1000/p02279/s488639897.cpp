#include <bits/stdc++.h>
#define Max 100005
int N;
struct Node{int p ,l,r;};
Node T[Max];
int D[Max];

void setDepth(int u, int p){
  D[u] = p;
  if(T[u].r != -1)setDepth(T[u].r, p);
  if(T[u].l != -1)setDepth(T[u].l, p+1);
}

void print(int u){
  printf("node %d: parent = %d, depth = %d, ", u, T[u].p, D[u]);
  if(T[u].p == -1)printf("root, ");
  else if(T[u].l == -1)printf("leaf, ");
  else printf("internal node, ");
  printf("[");

  for(int i=0, c = T[u].l; c != -1; ++i, c = T[c].r){
    if(i)printf(", ");
    printf("%d", c);
  }
  printf("]\n");
}

main()
{
  int id, k, c, l;
  scanf("%d", &N);
  for(int i=0; i<N; ++i)T[i].p = T[i].l = T[i].r = -1;

  for(int i=0; i<N; ++i){
    scanf("%d%d", &id, &k);

    for(int j=0; j<k; ++j){
      scanf("%d", &c);
      if(j == 0)T[id].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = id;
    }

  }

  for(int i=0; i<N; ++i){
    if(T[i].p == -1){
      setDepth(i, 0);
      break;
    }
  }

  for(int i=0; i<N; ++i)print(i);

}
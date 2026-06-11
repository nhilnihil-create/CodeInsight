#include <bits/stdc++.h>
using namespace std;
int par[10000], rank[10000];

void init(int n) {
  for (int i=0; i<n; i++) {
    par[i]=i;
    rank[i]=0;
  }
}
int find(int val) {
  if (val==par[val]) {
    return val;
  } else {
    par[val]=find(par[val]);
    return par[val];
  }
}
void unite(int x,int y) {
  x=find(par[x]);
  y=find(par[y]);
  par[x]=y;
  if (x==y) {
    return;
  }
  /*if (rank[x]<rank[y]) {
    par[x]=y;
  } else {
    par[y]=x;
    if (rank[x]==rank[y]) {
      rank[x]++;
    }
    }*/
}
bool same(int x,int y) {
  x=find(x);
  y=find(y);
  return x==y;
}
int main() {
  int n, q;
  cin >> n >> q;
  init(n);
  for (int i=0; i<q; i++) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com==0) {
      unite(x,y);
    } else {
      printf("%d\n",same(x,y));
    }
  }
  return 0;
}
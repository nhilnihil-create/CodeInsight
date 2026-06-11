#include <bits/stdc++.h>
using namespace std;
int u,v;
int n,m;
 
int fa[100005];
 
void init() {
  for(int i=1;i<=n;i++) {
    fa[i]=i;
  }
}
 
int get(int x) {
  if(fa[x]==x) {
    return x;
  }
  return fa[x]=get(fa[x]);
}
 
int main() {
  scanf("%d %d",&n,&m);
  init();
  for(int i=1;i<=m;i++) {
    scanf("%d %d",&u,&v);
    int x=get(u);
    int y=get(v);
    if(x!=y) {
      fa[y]=x;
    }
  }
  int cnt=0;
  for(int i=1;i<=n;i++) {
    if(fa[i]==i) {
      cnt++;
    }
  }
  printf("%d",cnt-1);
  return 0;
}
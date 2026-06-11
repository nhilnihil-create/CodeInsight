#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i < (int)(n);i++)
typedef long long ll;

vector <int> G[100006];
vector <int> EDGE[100006];
int v[100006];

void dfs(int i,int c,int p){
  int k = 1;
  int j;

  for(j = 0;j < G[i].size();j++){
    int u = G[i][j]; int t = EDGE[i][j];
    if(u == p) continue;
    if(k == c) k++;
    v[t] = k; k++;
    dfs(u,v[t],i);
  }
}

int main(){
  int n;
  int i,t;
  int a,b;
  int d = -999999;

  scanf("%d", &n);
  for(i = 0;i < n - 1;i++){
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    EDGE[a].push_back(i);
    G[b].push_back(a);
    EDGE[b].push_back(i);
  }

  for(i = 1;i <= n;i++){
    t = G[i].size();
    if(d < t){
      d = t;
    }
  }

  dfs(1,-1,-1);

  printf("%d\n", d);
  for(i = 0;i < n - 1;i++){
    printf("%d\n", v[i]);
  }

  return 0;
}
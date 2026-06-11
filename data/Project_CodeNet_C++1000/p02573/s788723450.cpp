#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& par){
  if(par[x] == x) return x;
  else{
    /* path compression */
    par[x] = find(par[x], par);
    return par[x];
  }
}

void unite(int x, int y, vector<int>& par, vector<int>& rank){
  int px = find(x, par), py = find(y, par);
  if(px == py) return;
  /* union by rank */
  if(rank[px] > rank[py]) par[px] = py;
  else par[py] = px;
  if(rank[px] == rank[py]) rank[x]++;
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> par(n), rank(n);
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
  }
  int a,b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    a--;b--;
    unite(a, b, par, rank);
  }
  vector<int> cnt(n);
  int ans = 0;
  for(int i=0; i<n; i++) cnt[find(i, par)]++;
  for(int i=0; i<n; i++) ans = max(ans, cnt[i]);
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, Q;
vector<vector<int> > G;
vector<int> ans;

void dfs(int now, int ago){
  for(auto next : G[now]){
    if(next == ago) continue;
    ans[next] += ans[now];
    dfs(next, now);
  }
}

int main(){
  scanf("%d %d", &n, &Q);
  G.resize(n);
  ans.resize(n, 0);
  for(int i = 0; i < n - 1; i++){
    int a, b; scanf("%d %d", &a, &b);
    --a; --b;
    G[a].push_back(b); G[b].push_back(a);
  }
  for(int i = 0; i < Q; i++){
    int p, x; scanf("%d %d", &p, &x);
    ans[p - 1] += x;
  }
  dfs(0, -1);
  for(int  i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
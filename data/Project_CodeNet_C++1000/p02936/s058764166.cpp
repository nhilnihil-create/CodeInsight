#include <bits/stdc++.h>
using namespace std;

int N, Q;
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
  cin >> N >> Q;
  G.resize(N);
  ans.resize(N, 0);
  for(int i = 0; i < N-1; i++){
    int a, b; cin >> a >> b;
    --a; --b;
    G[a].push_back(b); G[b].push_back(a);
  }
  for(int i = 0; i < Q; i++){
    int p, x; cin >> p >> x;
    ans[p-1] += x;
  }
  dfs(0, -1);
  for(int  i = 0; i < N; i++) cout << ans[i] << " ";
  cout << endl;
}
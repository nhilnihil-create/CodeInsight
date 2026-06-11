#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;
int maxi = 0;

void
dfs(int node, int color, vector<map<int, int>> &tree, vector<bool> &seen, vector<int> &ans)
{
  seen[node] = true;
  int inc = 1;
  for(auto child: tree[node]){
    if(seen[child.first]) continue;
    int child_color = (color + inc++) % maxi;
    int id = child.second;
    ans[id] = child_color;
    dfs(child.first, child_color, tree, seen, ans);
  }
}

int 
main() {

  int N; cin >> N;
  vector<bool> seen(N + 1, false);
  vector<int> ans(N + 1, 0);
  vector<map<int, int>> tree(N + 1);
  rep(i, 0, N - 1){
    int a, b; cin >> a >> b;
    tree[a][b] = i + 1;
    tree[b][a] = i + 1;
  }
  tree[0][1] = 0;
  tree[1][0] = 0;

  rep(i, 0, N){
    if(maxi < (int)tree[i].size()){
      if(i == 1) maxi = tree[i].size(), --maxi;
      else maxi = tree[i].size();
    } 
  }
  cout << maxi << endl;

  dfs(0, -2, tree, seen, ans);

  rep(i, 1, N){
    cout << ans[i] + 1 << endl;
  }

}
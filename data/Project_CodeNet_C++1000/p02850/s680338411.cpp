#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

void dfs(vector<vector<int>> &tree, int now, int bf, int bfuse, int mx, map<pair<int, int>, int> &ans){
  int use = 0;
  if(use == bfuse) use++;
  for(int i : tree.at(now)){
    if(i == bf) continue;
    int ii = i, nn = now;
    if(nn > ii) swap(nn, ii);
    pair<int, int> p = make_pair(nn, ii);
    if(ans.count(p) == 0){
      ans[p] = use;
      dfs(tree, i, now, use, mx, ans);
      use++;
      if(use == bfuse) use++;
    }
  }
}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> tree(n, vector<int>());
  vector<pair<int, int>> in(n-1);
  map<pair<int, int>, int> ans;
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    in.at(i) = make_pair(a, b);
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  int mx = 0;
  rep(i, n){
    mx = max(mx, (int)tree.at(i).size());
  }
  cout << mx << endl;
  dfs(tree, 0, -1, -1, mx, ans);
  rep(i, n-1){
    auto p = in.at(i);
    if(ans.count(p) == 1)cout << ans[p]+1 << endl;
    else return 1;
  }
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

void dfs(vector<vector<pair<int, int>>> &tree, vector<int> &ans, int now, int bfn, int bfc){
  int co = 0;
  rep(i, tree.at(now).size()){
    if(tree.at(now).at(i).first == bfn) continue;
    if(co == bfc) co++;
    ans.at(tree.at(now).at(i).second) = co;
    dfs(tree, ans, tree.at(now).at(i).first, now, co);
    co++;
  }
}

int main(){
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> tree(n, vector<pair<int, int>>());
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree.at(a).push_back({b, i});
    tree.at(b).push_back({a, i});
  }
  int mx = 0, index = -1;
  rep(i, n){
    if(tree.at(i).size() > mx){
      mx = tree.at(i).size();
      index = i;
    }
  }
  cout << tree.at(index).size() << endl;
  vector<int> ans(n-1);
  dfs(tree, ans, index, -1, -1);
  for(int i : ans){
    cout << i+1 << endl;
  }
  return 0;
}
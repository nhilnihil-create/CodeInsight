#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> to[200005];
vector<ll> ans;
void dfs(int root, int p=-1) {
  for(auto x : to[root]){
    if (x == p) continue;
    ans[x] += ans[root];
    dfs(x,root);
  }
}

int main(){
  int n, q;
  cin >> n >> q;
  ans.resize(n);
  rep(i,n-1){
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  rep(i,q){
    int p, x;
    cin >> p >> x;
    --p;
    ans[p] += x;
  }
  dfs(0);
  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
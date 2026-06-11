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

void dfs(const vector<vector<int>> &tree, vector<ll> &q, int now, int bf){
  if(now != 0) q.at(now) += q.at(bf);
  for(auto nx : tree.at(now)){
    if(nx == bf) continue;
    dfs(tree, q, nx, now);
  }
}

int main(){
  int n, qe;
  cin >> n >> qe;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector<ll> q(n, 0);
  rep(i, qe){
    int qin, x;
    cin >> qin >> x;
    qin--;
    q.at(qin) += x;
  }
  dfs(tree, q, 0, -1);
  rep(i, n){
    if(i != 0) cout << " ";
    cout << q.at(i);
  }
  cout << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<vector<int> > g(n, vector<int>(n, -1));//iさんがxさんのことをなんと証言したか
  rep(i, n){
    int a;
    cin >> a;
    rep(j, a){
      int x, y;
      cin >> x >> y;
      g.at(i).at(x-1) = y;
    }
  }

  int ans = 0;
  rep(i, 1 << n){
    vector<int> s(n);
    rep(j, n){
      if(i >> j & 1)
	s.at(j) = 1;
    }
    bool flag = true;
    rep(k, n){
      if(s.at(k)){
	rep(l, n){
	  if(g.at(k).at(l) == -1) continue;
	  if(g.at(k).at(l) != s.at(l)) flag = false;
	}
      }
    }
    if(flag) ans = max(ans, __builtin_popcount(i));
  }
  
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;

  vector<vector<int> > v(n, vector<int>(2, 0));
  rep(i, n){
    int a;
    cin >> a;
    rep(j, a){
      int x, y;
      cin >> x >> y;
      if (y == 0) v[i][0] |= (1 << (x-1));
      if (y == 1) v[i][1] |= (1 << (x-1));
    }
  }

  int ans = 0;
  rep(i, 1 << n){
    int h = 0;
    int u = 0;
    int count = 0;
    rep(j, n){
      if ((i>>j) & 1) {
        h |= v[j][1];
        u |= v[j][0];
        count++;
      }
    }
    if ((i == (i | h)) && (i == (i & ~u))){
      ans = max(ans, count);
    }
  }
  cout << ans << endl;
  return 0;
}
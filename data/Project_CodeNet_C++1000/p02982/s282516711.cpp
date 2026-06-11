#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool is_squere(int n) {
    int r = (int)floor(sqrt((long double)n));  // 切り捨てした平方根
    return (r * r) == n;
}

int main() {
  int n,d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep(i,0,n) rep(j,0,d) cin >> x[i][j];
  int ans = 0;
  rep(i,0,n-1) rep(j,i+1,n) {
    int dist = 0;
    rep(k,0,d) {
      dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
    }
    if (is_squere(dist)) ans++;
  }
  cout << ans << endl;
  return 0;
}
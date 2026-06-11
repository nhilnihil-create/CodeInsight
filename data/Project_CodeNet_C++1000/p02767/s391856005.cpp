#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  int mx = 1000;
  rep(i, n) {
    mx = max(mx, x[i]);
  }
  int ans = 1000000000;
  for(int i = 1; i <= ((1+mx)/2)+1; i++) {
    int sum = 0;
    rep(j, n) {
      int t = abs(x[j] - i);
      sum += t*t;
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
} 
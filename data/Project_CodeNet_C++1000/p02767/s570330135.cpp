#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep (i, n) cin >> x[i];
  ll ans = 10000000;
  for (int i = 0; i <= 100; i++){
    int s = 0;
    rep(j,n) {
      s+= (x[j] - i)*(x[j] - i);
    }
    if(s < ans) ans = s;
  }
  cout << ans << endl;
}



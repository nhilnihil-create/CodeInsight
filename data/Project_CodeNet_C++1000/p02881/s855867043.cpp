#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll ans;

int main() {
  double n;
  cin >> n;
  rep (i, sqrt(n)){
    if ((ll)n % i == 0) ans = (ll)n/i + i - 2;
  }
  cout << ans << endl;
  return 0;
}

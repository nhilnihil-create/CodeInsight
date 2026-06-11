#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  ll n, d;
  cin >> n >> d;
  ll ans = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (x * x + y * y <= d * d) ans++;
  }

  cout << ans << endl;
  return 0;
}
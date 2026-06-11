#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Pi acos(-1)

long long Pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll n;
  cin >> n;
  ll ans = 0;
  if (n%2 == 1) cout << 0 << '\n';
  else {
    rep(i,30) {
      ans += n/Pow(5,i+1)/10;
    }
    ans += n/10;
    cout << ans << '\n';
  }
}
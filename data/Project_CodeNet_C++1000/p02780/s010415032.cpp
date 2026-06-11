#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n) {
    cin >> a[i];
    if (i == 0) b[i]= a[i];
    else b[i] = b[i-1]+a[i];
  }
  ll ans = 0;
  rep(i,n-k+1) {
    ll tmp = 0;
    if (i == 0) {
      tmp = b[k-1];
    }
    else {
      tmp = b[k-1+i] - b[i-1];
    }
    ans = max(ans, tmp);
  }
  cout << (ans+k)/2.0 << '\n';
}
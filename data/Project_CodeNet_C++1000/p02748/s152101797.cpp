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
  ll a, b, m;
  cin >> a >> b >> m;
  vector<ll> s(a);
  vector<ll> t(b);
  rep(i,a) cin >> s[i];
  rep(i,b) cin >> t[i];
  ll ans = INF;
  rep(i, m) {
    ll x, y, c;
    cin >> x >> y >> c;
    ll tmp = s[x-1]+t[y-1]-c;
    ans = min(ans,tmp);
  }
  Sort(s);
  Sort(t);
  ll tmp = s[0]+t[0];
  cout << min(ans,tmp) << '\n';
}
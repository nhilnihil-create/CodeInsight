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
  ll n, m;
  cin >> n >> m;
  priority_queue<ll> a;
  ll b;
  rep(i,n) {
    cin >> b;
    a.push(b);
  }
  rep(i,m) {
    ll tmp = a.top()/2;
    a.pop();
    a.push(tmp);
  }
  ll ans = 0;
  while (!a.empty()) {
    ans += a.top();
    a.pop();
  }
  cout << ans << '\n';
}
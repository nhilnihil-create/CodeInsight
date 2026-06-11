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

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll n;
  cin >> n;
  vector<pair<ll,ll>> p(n); 
  rep(i,n) {
    ll a, b;
    cin >> a >> b;
    p[i] = {b,a};
  }
  Sort(p);
  ll nt = 0;
  rep(i,n) {
    nt += p[i].second;
    if (nt > p[i].first) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
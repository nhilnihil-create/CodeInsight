#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;

int tc(ll n) {
  ll c = 0;
  while(n%2 == 0) {
    ++c;
    n /= 2;
  }
  return c;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i] /= 2;
  }
  ll ans = a[n-1];
  rep(i,n-1) {
    ans = lcm(ans,a[i]);
  }
  ll t = tc(a[n-1]);
  rep(i,n-1) {
    if (t != tc(a[i])) {
      cout << 0 << '\n';
      return 0;
    }
  }
  cout << m/ans - m/(ans*2)<< '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n, m;
  cin >> n >> m;
  ll ac = 0;
  ll wa = 0;
  vector<bool> a(n, false);
  vector<ll> w(n);
  rep(i,m) {
    ll p;
    string s;
    cin >> p >> s;
    if (s == "AC" && a[p-1] == false) {
      a[p-1] = true;
      ++ac;
      wa += w[p-1];
    }
    if (s == "WA" && a[p-1] == false) {
      ++w[p-1];
    }
  }
  cout << ac << ' ' << wa << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll cnt[1000100];

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) {
    map<ll, ll> mp = prime_factor(a[i]);
    for (auto p: mp) cnt[p.first]++;
  }
  bool p = true;
  rep(i, 1000100) {
    if (cnt[i] > 1) {
      p = false;
      break;
    }
  }
  if (p) {
    cout << "pairwise coprime\n";
    return 0;
  }
  rep(i, 1000100) {
    if (cnt[i] == n) {
      cout << "not coprime\n";
      return 0;
    }
  }
  cout << "setwise coprime\n";

  
  return 0;
}
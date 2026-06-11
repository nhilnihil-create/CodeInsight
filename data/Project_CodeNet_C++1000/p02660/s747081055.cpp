#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) { a = b; return true; } return false; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n; cin >> n;
  map<int,int> m;

  rep2(i, 2, sqrt(n)) {
    while (n % i == 0) {
      ++m[i];
      n /= i;
    }
  }

  if (n != 1) ++m[n];

  int ans = 0;
  for (auto e : m) {
    int cnt = 1;

    while (e.se - cnt >= 0) {
      e.se -= cnt;
      ++cnt; ++ans;
    }
  }

  cout << ans << endl;

  return (0);
}

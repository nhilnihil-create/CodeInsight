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

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, m, k; cin >> n >> m >> k;
  vll a(n), b(m);

  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  vll sum_a(n+1, 0), sum_b(m+1, 0);
  rep(i, n) sum_a[i+1] += sum_a[i] + a[i];
  rep(i, m) sum_b[i+1] += sum_b[i] + b[i];

  ll ans = 0;
  int idx = m;

  rep(i, n+1) {
    ll tmp = k - sum_a[i];

    if (tmp < 0) continue;

    while (sum_b[idx] > tmp) --idx;
    chmax(ans, i+idx);
  }

  cout << ans << endl;

  return (0);
}

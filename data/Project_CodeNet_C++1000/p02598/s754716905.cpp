#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define ep emplace
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

  ll n, k; cin >> n >> k;
  vi a(n);
  rep(i, n) cin >> a[i];

  auto f = [&](ll len) {
    ll ret = 0;

    rep(i, n) ret += ((a[i] + len - 1) / len) - 1;
    return ret;
  };

  ll left = 0, right = 1e9;
  while (right - left > 1) {
    ll mid = (right + left) / 2;
    ll v = f(mid);

    if (v <= k) right = mid;
    else left = mid;
  }

  cout << right << endl;

  return (0);
}

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

  int k; cin >> k;
  int amari = 0, ans = 0;

  while (true) {
    ++ans;
    amari = (7 + amari * 10) % k;
    
    if (amari == 0) {
      cout << ans << endl;
      return (0);
    }

    if (ans >= 1000000) break;
  }

  cout << -1 << endl;

  return (0);
}

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

  int n; cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];

  sort(all(a));
  int left = a[n-1], right = a[0];
  vpi ans;

  rep2(i, 1, n-2) {
    if (a[i] < 0) {
      ans.eb(left, a[i]);
      left -= a[i];
    } else {
      ans.eb(right, a[i]);
      right -= a[i];
    }
  }

  cout << left - right << endl;
  for (auto p : ans) cout << p.fi << " " << p.se << endl;
  cout << left << " " << right << endl;

  return (0);
}

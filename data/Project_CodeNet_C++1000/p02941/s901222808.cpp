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
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  priority_queue<pair<ll, ll>> pq;
  rep(i, n) pq.push({b[i], i});
  ll ans = 0;
  while (!pq.empty()) {
    ll i = pq.top().second;
    pq.pop();
    if (b[i] < a[i]) break;
    if (b[i] == a[i]) continue;
    ll x = (b[i] - a[i]) / (b[(i - 1 + n) % n] + b[(i + 1) % n]);
    ans += x;
    b[i] -= x * (b[(i - 1 + n) % n] + b[(i + 1) % n]);
    if (x) pq.push({b[i], i});
  }
  cout << (a == b ? ans : -1) << '\n';


  




  
  return 0;
}
#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define debug(x) cout << #x << " = " << (x) << endl;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define uni(x) x.erase(unique(rng(x)),x.end())
#define SP << " " <<
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int mod = 1000000007;
const double EPS = 1e-9;
const int INF = 1<<30;
const ll INFLL = 1LL<<60;
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main () {
  ll t1, t2;
  cin >> t1 >> t2;
  ll a1, a2;
  cin >> a1 >> a2;
  ll b1, b2;
  cin >> b1 >> b2;

  ll p = (a1-b1)*t1;
  ll q = (a2-b2)*t2;

  if (p > 0) {
    p *= -1;
    q *= -1;
  }

  if (p+q < 0) cout << 0 << endl;
  else if (p+q == 0) cout << "infinity" << endl;
  else {
    ll s = (-p)/(p+q);
    ll t = (-p)%(p+q);
    if (t != 0) cout << 1 + 2*s << endl;
    else cout << 2*s << endl;
  }
  return 0;
}
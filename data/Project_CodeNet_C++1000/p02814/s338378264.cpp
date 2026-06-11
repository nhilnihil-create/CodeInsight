#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define fout(x) cout << fixed << setprecision(10) << x << endl
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

auto print = [](auto &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
};

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  if (a < b) swap(a, b);
  return (a / gcd(a, b)) * b;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  VL a(n), b(n), c(n);
  ll l = 1;
  bool flag = true;
  rep(i, n) {
    cin >> a[i];
    b[i] = a[i] / 2;
    l = lcm(l, b[i]);
    if(l > m) {
      flag = false;
      break;
    }
  }
  if(flag) {
    rep(i, n) {
    c[i] = l / b[i];
    if(c[i] % 2 == 0) flag = false;
    }
  }
  ll ans = 0;
  if(flag) {
    ans = ceil((m / l + 1) / 2);
  }
  out(ans);


  return 0;
}

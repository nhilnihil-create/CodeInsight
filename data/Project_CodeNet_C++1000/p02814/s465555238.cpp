#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

ll f(ll x) {
  int res = 0;
  while (x % 2 == 0) {
    x /= 2;
    res++;
  }
  return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void solve(ll N, ll M, std::vector<ll> a) {
  rep(i, N) { a.at(i) /= 2; }

  ll t = f(a.at(0));
  rep(i, N) {
    if (t != f(a.at(i))) {
      cout << 0 << endl;
      return;
    }
    a.at(i) >>= t;  // a.ati /= 2^t
  }
  M >>= t;

  ll l = 1;
  rep(i, N) {
    l = lcm(l, a.at(i));
    if (l > M) {
      cout << 0 << endl;
      return;
    }
  }

  M /= l;
  int ans = (M + 1) / 2;
  cout << ans << endl;
}

int main() {
  ll N;
  scanf("%lld", &N);
  ll M;
  scanf("%lld", &M);
  std::vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, M, std::move(a));
  return 0;
}

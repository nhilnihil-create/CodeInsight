#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const long long MOD = 1000000007;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

void solve(ll N, std::vector<ll> A) {
  ll p = 0, q = 0, r = 0;
  ll x = 1;

  rep(i, N) {
    int cnt = 0;
    if (p == A.at(i)) cnt++;
    if (q == A.at(i)) cnt++;
    if (r == A.at(i)) cnt++;

    if (p == A.at(i)) {
      p += 1;
    } else if (q == A.at(i)) {
      q += 1;
    } else if (r == A.at(i)) {
      r += 1;
    }

    x *= cnt;
    x %= MOD;
  }

  cout << x % MOD << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll N;
  scanf("%lld", &N);
  std::vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}

#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

ll solve(ll N, std::vector<ll> A) {
  vector<ll> B(N + 1);
  B.at(0) = 1 - A.at(0);
  if (B.at(0) < 0) return -1;

  ll result = A.at(0) + B.at(0);
  ll asum = 0;
  rep(j, N + 1) { asum += A.at(j); }
  FOR(i, 1, N + 1) {
    ll d = B.at(i - 1) * 2;
    asum -= A.at(i - 1);
    d = min(B.at(i - 1) * 2, asum);
    B.at(i) = d - A.at(i);

    if (A.at(i) < 0 || B.at(i) < 0) return -1;
    result += A.at(i) + B.at(i);
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll N;
  scanf("%lld", &N);
  std::vector<ll> A(N - 0 + 1);
  for (int i = 0; i < N - 0 + 1; i++) {
    scanf("%lld", &A[i]);
  }
  ll result = solve(N, std::move(A));
  cout << result << endl;
  return 0;
}

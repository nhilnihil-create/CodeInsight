#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

const int N = 1000010;

int main() {
  int n, m, h[N], ma[N];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    ma[i] = 0;
  }

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    ma[a] = max(ma[a], h[b]);
    ma[b] = max(ma[b], h[a]);
  }

  int ans = 0;
  rep(i, n + 1) ans += h[i] > ma[i];
  cout << ans << endl;
  return 0;
}
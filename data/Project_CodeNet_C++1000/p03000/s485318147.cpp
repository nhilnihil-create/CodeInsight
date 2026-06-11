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

int main() {  // TODO
  int N, X;
  cin >> N >> X;
  vector<int> L(N + 1);
  rep(i, N) cin >> L[i + 1];

  int ans = 0;
  int d = 0;
  if (d <= X) ans++;
  if (N == 1) {
    cout << ans << endl;
    return 0;
  }
  for (int i = 2; i <= N + 1; i++) {
    d = d + L[i - 1];
    if (d <= X) ans++;
  }
  cout << ans << endl;
  return 0;
}
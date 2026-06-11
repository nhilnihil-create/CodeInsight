#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define dbl(k, x) fixed << setprecision(k) << (x)

template <typename _T>
inline void _DBG(const char *s, _T x) {
  cerr << s << " = " << x << "\n";
}
template <typename _T, typename... args>
void _DBG(const char *s, _T x, args... a) {
  while (*s != ',') cerr << *s++;
  cerr << " = " << x << ',';
  _DBG(s + 1, a...);
}

#define _upgrade                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)

// ********************** CODE ********************** //

LL dp[2005][2005];

int main() {
  _upgrade;
  int n;
  cin >> n;

  vector<PLL> A(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A[i] = {a, i};
  }
  sort(all(A));
  reverse(all(A));

  for (int i = 0; i < n; i++) {
    LL val, pos;
    tie(val, pos) = A[i];

    for (int front = i; front >= 0; front--) {
      int back = i - front;
      dp[front + 1][back] =
          max(dp[front + 1][back], dp[front][back] + val * abs(front - pos));
      dp[front][back + 1] = max(
          dp[front][back + 1], dp[front][back] + val * abs(n - 1 - back - pos));
    }
  }

  LL res = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i + j == n) {
        res = max(res, dp[i][j]);
      }
    }
  }

  cout << res << "\n";
  return 0;
}
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
  int N, K, R, S, P;
  cin >> N >> K;
  vector<int> A(3);
  rep(i, 3) cin >> A[i];
  vector<char> J(N);
  rep(i, N) cin >> J[i];
  vector<int> ctoi(256);
  ctoi['r'] = 2;
  ctoi['c'] = 0;
  ctoi['p'] = 1;
  int ans = 0;

  rep(i, K) {
    vector<int> x;
    for (int j = i; j < N; j += K) {
      x.push_back(ctoi[J[j]]);
    }
    vector<int> dp(2);
    int pre = -1;
    for (int nx : x) {
      vector<int> p(2);
      swap(dp, p);
      dp[0] = max(p[0], p[1]);
      if (pre == nx) {
        dp[1] = p[0] + A[nx];
      } else {
        dp[1] = max(p[0], p[1]) + A[nx];
      }
      pre = nx;
    }
    ans += max(dp[0], dp[1]);
  }
  cout << ans << endl;

  return 0;
}
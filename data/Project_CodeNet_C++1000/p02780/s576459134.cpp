#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  rep(i, N) cin >> P[i];
  int ans = 0;
  int temp = 0;
  for (int i = 0; i < N; i++) {
    temp += (1 + P[i]);
    if (i >= K) temp -= (1 + P[i-K]);
    ans = max(ans, temp);
  }
  double x = double(ans) / 2.0;
  printf("%.8f\n", x);
  return 0;
}
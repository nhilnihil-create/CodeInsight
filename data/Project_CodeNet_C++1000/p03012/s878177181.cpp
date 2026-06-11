#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> W(N);
  rep(i, N) cin >> W[i];

  int ans = 1 << 30;
  int A, B;
  for (int T = 1; T < N; T++) {
    A = 0;
    B = 0;
    rep(i, T) A += W[i];
    rep(i, N - T) B += W[T + i];
    ans = min(ans, abs(A - B));
  }
  cout << ans << endl;
  return 0;
}
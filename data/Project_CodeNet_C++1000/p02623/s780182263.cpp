#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll N, M, K;
  cin >> N >> M >> K;
  vector<ll> A(N + 1, 0), B(M + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    A[i] += A[i - 1];
  }
  for (int i = 1; i <= M; i++) {
    cin >> B[i];
    B[i] += B[i - 1];
  }
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    int tk = K;
    tk -= A[i];
    if (tk < 0) break;
    auto iter = upper_bound(B.begin(), B.end(), tk);
    ans = max(ans, i + (int)(iter - B.begin()) - 1);
  }

  cout << ans << endl;
}

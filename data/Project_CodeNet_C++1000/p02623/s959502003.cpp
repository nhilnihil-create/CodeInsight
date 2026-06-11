#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<ll> A(N+1,0), B(M+1,0);
  rep(i,N) cin >> A[i+1];
  rep(i,M) cin >> B[i+1];

  rep(i, N) A[i+1] += A[i];
  rep(i, M) B[i+1] += B[i];

  int ans = 0;
  int i_A = 0, i_B = M;
  while (i_A <= N) {
    int time = A[i_A];
    while (i_B >= 0 && time + B[i_B] > K) i_B--;
    if (i_B == -1) break;
    ans = max(ans, i_A + i_B);
    i_A++;
  }
  cout << ans << endl;
  return 0;
}
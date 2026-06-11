#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N), B(N + 1);
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    B[i + 1] = B[i] + A[i];
  }

  for (int i = 1; i <= N; i++) {
    B[i] = (B[i] - i) % K;
  }

  map<ll, ll> m;
  for (int i = 0; i <= N; i++) {
    if (i - K >= 0) m[B[i - K]]--;
    ans += m[B[i]];
    m[B[i]]++;
  }
  cout << ans << endl;
}
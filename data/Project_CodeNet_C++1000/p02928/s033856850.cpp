#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), B(N), C(N);
  ll ret = 0;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (A[i] > A[j]) {
        B[i]++;
      }
    }
    for (int j = i + 1; j < N; j++) {
      if (A[i] > A[j]) {
        C[i]++;
      }
    }
    ret = (ret + MOD + (K * (K - 1) / 2) % MOD * B[i] % MOD) % MOD;
    ret = (ret + MOD + (K * (K + 1) / 2) % MOD * C[i] % MOD) % MOD;
  }
  cout << ret << endl;
}
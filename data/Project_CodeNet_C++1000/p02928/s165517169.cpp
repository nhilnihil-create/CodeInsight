#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long int K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  long long int ans = 0, MOD = 1000000007;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A.at(i) < A.at(j)) ans = (ans + K * (K - 1) / 2 % MOD) % MOD;
      else if (A.at(i) > A.at(j)) ans = (ans + K * (K + 1) / 2 % MOD) % MOD;
    }
  }
  
  if (ans < 0) ans += MOD;
  cout << ans << endl;
}
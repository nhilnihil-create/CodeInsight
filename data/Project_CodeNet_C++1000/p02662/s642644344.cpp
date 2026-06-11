#include<iostream>
using namespace std;

#define MOD 998244353

#define INV2 499122177

long dp[3010];

int main() {
  int N, S; cin >> N >> S;
  int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < 3010; i++) dp[i] = 0;
  dp[0] = 1;
  for (int i = 0; i < N; i++) dp[0] = dp[0] * 2 % MOD;
  for (int i = 0; i < N; i++) {
    for (int j = S - A[i]; j >= 0; j--) {
      dp[j+A[i]] = (dp[j+A[i]] + dp[j]*INV2%MOD)%MOD;
    }
  }
  cout<<dp[S]<<endl;
}
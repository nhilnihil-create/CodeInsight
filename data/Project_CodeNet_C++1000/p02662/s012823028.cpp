#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD (998244353)
int main(void) {
  int N, S;
  cin >> N >> S;
  vector <long long> dp(S+1);
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    int A;
    cin >> A;
    vector <long long> p(S+1);
    swap(dp, p);
    for (int i = 0; i <= S; i++) {
      dp[i] += p[i]+p[i];
      dp[i] %= MOD;

      if (i+A <= S) {
        dp[i+A] += p[i];
        dp[i+A] % MOD;
      }
    }
  }
  cout << dp[S] << endl;
  return 0;
}

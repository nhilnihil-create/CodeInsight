#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  long long N, P;
  cin >> N >> P;
  string S;
  cin >> S;
  
  long long dp[N];
  long long pow_10 = 1;
  for (int i = N - 1; i >= 0; i--){
    if (i == N - 1) dp[i] = (S[i] - '0') % P;
    else {
      dp[i] = dp[i + 1] + (S[i] - '0') * pow_10;
      dp[i] %= P;
    }
    pow_10 *= 10; pow_10 %= P;
  }
  
  long long sum[P];
  for (int i = 0; i < P; i++) sum[i] = 0;
  for (int i = 0; i < N; i++){
    sum[dp[i]]++;
  }
  sum[0]++;
  long long count = 0;
  for (int i = 0; i < P; i++) count += sum[i] * (sum[i] - 1) / 2;
  if (P != 2 && P != 5) cout << count << endl;
  else {
    if (P == 2){
      long long sum = 0;
      for (int i = 0; i < N; i++) if ((S[i] - '0') % 2 == 0) {
        sum += i + 1;
      }
      cout << sum << endl;
    }
    if (P == 5){
      long long sum = 0;
      for (int i = 0; i < N; i++) if ((S[i] - '0') % 5 == 0) {
        sum += i + 1;
      }
      cout << sum << endl;
    }
  }
}
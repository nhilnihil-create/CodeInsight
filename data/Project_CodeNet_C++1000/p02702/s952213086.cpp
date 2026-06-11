#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  long long N = S.size();
  long long dp[N];
  long long pow_10 = 1;
  for (int i = N - 1; i >= 0; i--){
    if (i == N - 1) dp[i] = S[i] - '0';
    else dp[i] = (dp[i + 1] + (S[i] - '0') * pow_10) % 2019;
    pow_10 *= 10; pow_10 %= 2019;
  }
  long long count = 0;
  long long sum[2019];
  for (int i = 0; i < 2019; i++) sum[i] = 0;
  for (int i = 0; i < N; i++){
    sum[dp[i]]++;
  }
  sum[0]++;
  for (int i = 0; i < 2019; i++){
    count += sum[i] * (sum[i] - 1) / 2;
  }
  cout << count << endl;
}
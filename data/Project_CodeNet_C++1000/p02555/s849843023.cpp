#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int mod = 1000000007; 

int main() {
  int s;
  cin >> s;
  vector<ll> dp(s+1);
  // dp[n] = number of sequences whose terms are all integers 
  // greater than or equal to 3 and whose sum is equal to n

  dp[0] = 1;  // there is only one way to get sum 0: take nothing
  for (int sum = 3; sum <= s; sum++) {
    for (int elmt = 3; elmt <= sum; elmt++) {
      dp[sum] += dp[sum-elmt];
      dp[sum] %= mod;
    }
  }
  cout << dp[s];
}

/*
*****Another approach*****
For example, dp[0] to dp[9] will be:
dp[0] -> {9}
dp[1] -> {}
dp[2] -> {}
dp[3] -> {3}
dp[4] -> {4}
dp[5] -> {5}
dp[6] -> {6},{3,3}
dp[7] -> {7},{3,4},{4,3}
dp[8] -> {8},{3,5},{4,4},{5,3}
dp[9] -> {9},{3,6},{4,5},{5,4},{6,3},{3,3,3}

By adding number into each sequence to dp[6] that makes the sum of a sequence to be 9,
one can see that all sequences of dp[9] appears in dp[0] to dp[6]
dp[0] -> {9}
dp[3] -> {3,6}
dp[4] -> {4,5}
dp[5] -> {5,4}
dp[6] -> {6,3},{3,3,3}

Therefore,
dp[9] = dp[0] + dp[1] + ... + dp[6]
Generalize above,
dp[n] = dp[0] + dp[1] + ... + dp[n-3] --- (1)
Moreover,
dp[n+1] = dp[0] + dp[1] + ... + dp[n-3] + dp[n-2]
        = dp[n] + dp[n-2]
Thus,
dp[n] = d[n-1] + dp[n-3] --- (2)

Use (1) or (2)

'''
dp[0] = 1; dp[1] = 0; dp[2] = 0;
for (int i = 3; i <= s; i++) {
  dp[i] = dp[i-1] + dp[i-3];  // (2)
  dp[i] %= mod;
}
'''
*/

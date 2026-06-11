#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
ll ans = 0;

const ll INF = 1LL << 60;
template<class T> inline bool chmin(T& a, T b) {
  if(a > b) {
    a = b;
    return true;
  }

  return false;
}

template<class T> inline bool chmax(T& a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  string S;
  cin >> S;
  ll dp[S.size()][13] = {0};
  reverse(S.begin(), S.end());
  ll keta = 1;
  if(S[0] == '?') {
    for(int i = 0; i < 10; i++) {
      dp[0][i] = 1;
    }
  } else {
    int t = S[0] - '0';
    dp[0][t] = 1;
  }

  for(int i = 1; i < S.size(); i++) {
    keta *= 10;
    keta %= 13;
    if(S[i] == '?') {
      for(int j = 0; j < 10; j++) {
        for(int k = 0; k < 13; k++) {
          dp[i][(keta * j + k) % 13] += dp[i - 1][k];
          dp[i][(keta * j + k) % 13] %= 1000000007;
        }
      }
    }
    else {
      int t = S[i] - '0';
      for(int j = 0; j < 13; j++) {
      dp[i][(t * keta + j) % 13] += dp[i - 1][j]; 
      dp[i][(t * keta + j) % 13] %= 1000000007;
      }
    }
  }
    cout << dp[S.size() - 1][5];



  return 0;
}
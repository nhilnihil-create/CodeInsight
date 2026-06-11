#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const int M = 1000005;

int main() {
  string S;
  cin >> S;
  set<string> s;
  int n = S.length();
  if(n == 1){
    cout << "1¥n";
    return 0;
  }
  if(n == 2){
    if(S[0] == S[1]){
      cout << "1¥n";
    }else{
      cout << "2¥n";
    }
    return 0;
  }

  int dp[n];

  dp[0] = 1;

  if(S[0] == S[1]){
    dp[1] = 1;
  }else{
    dp[1] = 2;
  }

  if(S[0] != S[1] && S[1] != S[2]){
    dp[2] = 3;
  }else{
    dp[2] = 2;
  }

  for(int i = 3; i < n; i++){
    if(S[i-1] == S[i]){
      dp[i] = dp[i-3]+2;
    }else{
      dp[i] = dp[i-1]+1;
    }
  }
  cout << dp[n-1] << endl;
}


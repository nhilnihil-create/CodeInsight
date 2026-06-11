#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;


int main(void){
  string s;
  cin >> s;
  int n = s.size();
  ll hoge = 3;


  vector<ll> dp(s.size() + 2, 1);

  dp[1] = (s[s.size() - 1] == '1' ? 3 : 1);

  for (int i = 2; i <= n; i++){
    if (s[s.size() - i] == '1'){
      dp[i] = (2*dp[i-1] + hoge) % MOD;
    }
    else {
      dp[i] = (dp[i-1]) % MOD;
    }
    hoge = 3 * hoge % MOD;
  }

  cout << dp[n] << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)(n);i++)
typedef long long ll;

#define MODSIZE 1000000007

char s[100006];
ll dp[100005][13];

int main(){
  ll n;

  scanf("%s", s);
  n = strlen(s);

  int i,j;

  for(i = 0;i <= n;i++){
    for(j = 0;j <= 12;j++) dp[i][j] = 0;
  }

  dp[0][0] = 1;

  int k;

  for(i = 0;i < n;i++){
    for(j = 0;j < 13;j++){
      if(s[i] == '?'){
        for(k = 0;k < 10;k++){
          dp[i + 1][(j*10 + k) % 13] = (dp[i + 1][(j*10 + k) % 13] + dp[i][j]) % MODSIZE;
        }
      }

      else {
        k = s[i] - '0';
        dp[i + 1][(j*10 + k) % 13] = (dp[i + 1][(j*10 + k) % 13] + dp[i][j]) % MODSIZE;
      }
    }
  }

  printf("%lld\n", dp[n][5]);

  return  0;
}

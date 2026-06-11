#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXN 100001
int dp[MAXN][2];

int main(){
  string s; cin>>s;
  int n = s.size();

  //dp[i][j]:sをi文字目まで見た時のa+bの種類数、j=1の時はその数がL未満であることが確定している、j=0の時はその数はi文字目まではLと一致している。
  dp[0][0]=1;
  rep(i, n){
    {//a+bのi bit目が0
      if(s[i]=='0'){
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
      }else{
        dp[i+1][1] = (dp[i][0] + dp[i][1])%MOD;
      }
    }
    {//a+bのi bit目が1
      if(s[i]=='0'){
        //a+bのi文字目が1でsのi文字目が0であれば、a+bがLよりもでかくなることが確定するので、それまでの数字が一致しているs[i][0]は使用不可、a+b<Lが確定しているdp[i][1]のみが使用可能。そして数字の組み合わせは反転させることで2倍になる。
        (dp[i+1][1] += dp[i][1]*2%MOD) %= MOD;
      }else{
        (dp[i+1][0] += dp[i][0]*2%MOD) %= MOD;
        (dp[i+1][1] += dp[i][1]*2%MOD) %= MOD;
      }
    }
  }
  cout<<(dp[n][0]+dp[n][1]) % MOD<<endl;

  return 0;
}
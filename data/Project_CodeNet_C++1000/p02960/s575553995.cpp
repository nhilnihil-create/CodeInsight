// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(18);
}
#define MOD 1000000007
signed main(){
  init_io();
  string s;
  cin >> s;
  ll n,val;
  n = s.size();
  ll dp[n+1][13]; //i番目まで見た時、13で割った余りがjになる数
  fill(dp[0],dp[n+1],0);
  dp[0][0] = 1;
  for(int i=0;i<n;i++){
    if(s[i]!='?'){
      val = s[i]-'0';
      for(int j=0;j<13;j++){
        ll nxt = ((j*10) + val)%13;
        dp[i+1][nxt] += dp[i][j];
        dp[i+1][nxt] %= MOD;
      }
    }else{
      for(int val=0;val<10;val++){
        for(int j=0;j<13;j++){
          ll nxt = ((j*10) + val)%13;
          dp[i+1][nxt] += dp[i][j];
          dp[i+1][nxt] %= MOD;
        }
      }
    }
  }
  cout << dp[n][5]<<endl;
}

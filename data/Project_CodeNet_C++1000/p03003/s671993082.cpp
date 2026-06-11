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
#define MOD 1000000007
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
ll dp[3000][3000]={};
signed main(){
  init_io();
  ll n,m;
  cin >> n >> m;
  vector<ll> s(n),t(m);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  for(int i=0;i<m;i++){
    cin >> t[i];
  }
  for(int i=0;i<=n;i++){
    dp[i][0]=1;
  }
  for(int i=0;i<=m;i++){
    dp[0][i]=1;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1];
      if(s[i]!=t[j]){
        dp[i+1][j+1] -= dp[i][j];
      }
      dp[i+1][j+1]%= MOD;
    }
  }
  ll v = dp[n][m];
  while(v<0) v+= MOD;
  v%= MOD;
  cout << v << endl;
}

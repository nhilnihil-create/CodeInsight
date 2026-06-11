#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long int ll;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define MOD 1000000007;

ll dp[2020][2020];
int ac[2001][100001];
int main(){
  int n,m; cin >> n >> m;
  rep(i,2020) rep(j, 2020) dp[i][j] = 0;
  rep(i,n+1) dp[i][0] = 1;
  rep(i,m+1) dp[0][i] = 1;
  vector<long long int> s(n), t(m);
  for(int i=0;i<n;i++) cin >> s[i];
  for(int i=0;i<m;i++) cin >> t[i];
  for(int i=1;i<n+1;i++) for(int j=0;j<100001;j++) ac[i][j] = 0;
  for(int j=0;j<100001;j++) ac[0][j] = 0;

  for(int j=1;j<=m;j++){
    for(int i=0;i<=n;i++) ac[i][t[j-1]] = (ac[i][t[j-1]] + dp[i][j-1]) % MOD;
    for(int i=1;i<=n;i++){
      ll sum = 0;
      // for(int k=j-1;k>=0;k--) if(s[i-1]==t[k]) sum = (dp[i-1][k] + sum) % MOD;
      sum =  (sum + ac[i-1][s[i-1]]) % MOD;
   //   cout << ac[i-1][s[i-1]] << endl;
      dp[i][j] = (dp[i-1][j] + sum)%MOD;
    }
    
  }
  rep(i,n+1){
  //  rep(j,m+1) cout << dp[i][j] << " ";
//    cout << endl;
  }
 cout << dp[n][m] << endl;
  return 0;
}
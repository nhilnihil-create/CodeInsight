#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1010101010

using namespace std;

int main(){
  string s;cin>>s;
  reverse(s.begin(), s.end());
  s+='0';
  int n=s.size();
  
  int dp[n+1][2];
  rep(i, n+1)rep(j, 2)dp[i][j]=INF;
  dp[0][0]=0;
  
  rep(i, n)rep(j, 2){
    int x=s[i]-'0'+j;
    
    if(x<10)dp[i+1][0] = min(dp[i+1][0], dp[i][j]+x);
    if(x>0)dp[i+1][1] = min(dp[i+1][1], dp[i][j] + (10-x));
  }
  
  cout<<dp[n][0]<<endl;

  return 0;
}

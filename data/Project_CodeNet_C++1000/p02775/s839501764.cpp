#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 100000000000

#define MAXN 1000001

using namespace std;

int dp[MAXN][2];

int main(){
  string s;cin>>s;
  reverse(s.begin(), s.end());
  s+='0';
  int n=s.size();

  rep(i, n+1)rep(j, 2)dp[i][j]=INF;
  dp[0][0]=0;
//  dp[0][1]=0;
  
  rep(i, n)rep(j, 2){
    int x = s[i]-'0'+j;
    rep(a, 10){
      int ni = i+1;
      int nj = 0;
      int b = a-x;
      if(b<0){
        nj=1;
        b+=10;
      }
      dp[ni][nj] = min(dp[ni][nj], dp[i][j]+a+b);
    }
  }

  cout<<dp[n][0]<<endl;

  return 0;
}
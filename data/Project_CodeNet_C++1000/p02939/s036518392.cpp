#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b);
#define chmin(a, b) (a)=min(a, b);
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/



int main(void) {
  ll i, j, k;
  
  string s;
  cin >> s;
  ll N=s.size();
  ll dp[MAX*2][3]={};
  
  s="#"+s;
  dp[1][1]=1;
  dp[2][1]=(s[1]==s[2]) ? 0 : 2;
  dp[2][2]=1;
  for(i=1; i<=N; i++) {
    if(i>=2 && s.substr(i-1, 2)!=s.substr(i+1, 2))
      chmax(dp[i+2][2], dp[i][2]+1);
    if(s.substr(i, 1)!=s.substr(i+1, 1))
      chmax(dp[i+1][1], dp[i][1]+1);
    if(i>=2)
      chmax(dp[i+1][1], dp[i][2]+1);
    
    chmax(dp[i+2][2], dp[i][1]+1);
  }
  
  
  pt(max(dp[N][1], dp[N][2]));
  
}




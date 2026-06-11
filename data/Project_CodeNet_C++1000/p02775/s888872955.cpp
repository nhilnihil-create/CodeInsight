#include <bits/stdc++.h>
#include <string>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

ll dp[MAX*10][2];

int main(void) {
  ll i, j, k, l;
  
  string L;
  cin >> L;
  ll N=L.size();
  
  for(i=0; i<=N; i++) for(j=0; j<2; j++) dp[i][j]=INF;
  
  dp[0][0]=0;
  dp[0][1]=1;
  for(i=0; i<N; i++) {
    ll c=L[i]-'0';
    dp[i+1][0]=min(dp[i][0]+c, dp[i][1]+(10-c));
    dp[i+1][1]=min(dp[i][0]+c+1, dp[i][1]+(10-c-1));
  }
  
  pt(dp[N][0]);
  
}


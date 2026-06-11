#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define PP pair<P,P>
using namespace std;

ll dp[2005][2005];
ll sum[2005][2005];

int main(){
int n,m; cin >> n >> m;
  int s[n];
  int t[m];
  rep(i,n) cin >> s[i];
  rep(i,m) cin >> t[i]; 
  rep(i,n+1) sum[i][0]=0;
  rep(i,m+1) sum[0][i]=0;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+dp[i-1][j-1];
        sum[i][j]%=MOD;
        if(sum[i][j]<0) sum[i][j]+=MOD;
        if(s[i-1]==t[j-1]) dp[i][j]=sum[i][j]+1;
        else dp[i][j]=0;
        dp[i][j]%=MOD;
    }
  }

  ll ans=1;
  rep(i,n+1)rep(j,m+1){
      ans+=dp[i][j];
      ans%=MOD;
  }
  cout << ans << endl;
return 0;
}


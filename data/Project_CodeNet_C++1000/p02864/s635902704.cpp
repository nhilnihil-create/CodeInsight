#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int N = 2e6+5;
const dd eps = 1e-8;
const ll mod = 1e9+7;

ll dp[305][305],n,k,a[305],ans=LLONG_MAX;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>n>>k;
  for(int i = 0;i <= n+1;i++){
    for(int j = 0;j <= k;j++) dp[i][j] = 1e12;
  }
  for(int i = 1;i <= n;i++) cin>>a[i];
  a[++n] = 0;
  dp[0][0] = 0ll;
  for(int i = 1;i <= n;i++){
    for(int j = 0;j <= min(k,(ll)i);j++){
      for(int p = 0;p <= j;p++){
	int pos = i-p-1;
	if(pos < 0) break;
	dp[i][j] = min(dp[i][j],dp[pos][j-p] + max(0ll,a[i]-a[pos]));
      }
    }
  }
  for(int i = 0;i <= k;i++) ans = min(ans,dp[n][i]);
  cout<<ans<<endl;
  return 0;
}

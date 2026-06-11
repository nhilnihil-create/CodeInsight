#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int N, M; cin >> N >> M;

  vector<ll> dp(N+1,-1);
  dp[0]=1;
  int a[M]; 
  rep(i,M) {
    cin >> a[i];
    dp[a[i]] = 0;
  }

  int MOD = 1000000007;
  for (int i=1;i<=N;i++){
    if (dp[i]==0) continue;

    if (i==1) dp[i] = dp[i-1];
    else dp[i] = (dp[i-1] + dp[i-2])%MOD;
  }
  cout << dp[N] << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}

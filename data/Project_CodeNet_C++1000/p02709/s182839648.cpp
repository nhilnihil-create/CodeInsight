#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 2005
#define INF 10000000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

int n;

P A[SIZE];

ll dp[SIZE][SIZE];

int main(){

  cin >> n;
  rep(i,0,n){
    cin >> A[i+1].first;
    A[i+1].second = (ll)i+1LL;
  }
  sort(A+1,A+n+1,greater<P>());

 dp[0][0] = 0;
 rep(i,0,n+1) rep(j,0,n+1) if(i+j != 0) if(i+j <= n) {
   ll p1 = (ll)i;
   ll p2 = (ll)(n-j+1);
   ll m1,m2;m1=m2=-INF;
   if(i-1>=0) m1 = A[i+j].first*(A[i+j].second-p1) + dp[i-1][j];
   if(j-1>=0) m2 = A[i+j].first*(p2-A[i+j].second) + dp[i][j-1];

   dp[i][j] = max(m1,m2);
 }

 /*
 rep(i,0,n+1) {
   rep(j,0,n+1) cout << dp[i][j] << " ";
   cout << endl;
 }
 */

 ll ans = 0;
 rep(i,0,n+1){
   ans = max(ans,dp[i][n-i]);
 }
 cout << ans << endl;

  return 0;
}

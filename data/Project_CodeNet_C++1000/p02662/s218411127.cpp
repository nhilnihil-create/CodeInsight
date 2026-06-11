#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 998244353
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;
ll dp[3333][3333];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,s;cin>>n>>s;
  vi A(n);
  for(auto &a:A){
    cin>>a;
  }
  dp[0][0] = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<=s;j++){
      dp[i+1][j] += dp[i][j]*2;
      dp[i+1][j] %= MOD;
      if(j+A[i] <= s){
	dp[i+1][j+A[i]] += dp[i][j];
      }
    }
  }
  cout<<dp[n][s]<<endl;
  return 0;
}

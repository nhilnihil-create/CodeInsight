#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll dp[111111][2];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;cin>>s;
  ll n = s.size();
  dp[0][1] = 1;
  for(int i=0;i<n;i++){
    if(s[i] == '0'){
      dp[i+1][1] = dp[i][1];
      dp[i+1][0] = dp[i][0]*3;
      dp[i+1][0]%=MOD;
    }else{
      dp[i+1][1] = (dp[i][1]*2)%MOD;
      dp[i+1][0] = (dp[i][1]+dp[i][0]*3)%MOD;
    }
  }
  cout<<(dp[n][1]+dp[n][0])%MOD<<endl;
  return 0;
}

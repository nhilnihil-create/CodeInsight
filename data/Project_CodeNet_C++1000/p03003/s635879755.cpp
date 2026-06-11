#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
int main(){
  int n,m;cin>>n>>m;
  vi a(n),b(m);
  rep(i,n)cin>>a[i];
  rep(i,m)cin>>b[i];
  vvi dp(n+1,vi(m+1,1));
  rep(i,n){
    rep(j,m){
      if(a[i]!=b[j])dp[i+1][j+1]=(mod+dp[i][j+1]+dp[i+1][j]-dp[i][j])%mod;
      else dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1])%mod;
      }
    }
  cout<<dp[n][m]%mod<<endl;
}

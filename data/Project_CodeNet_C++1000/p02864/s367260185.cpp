#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef multiset<ll> S;
typedef priority_queue<ll> PQ;
typedef priority_queue<P,vector<P>,greater<P>> SPQ;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double pi=3.14159265358979323846;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
void outvi(vi v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
void outvvi(vvi v){rep(i,v.size()){rep(j,v[i].size()){if(j)cout<<' ';cout<<v[i][j];}cout<<endl;}}

int main(){
    ll n,k;cin>>n>>k;
    vi v(n+1);
    v[0]=0;
    rep(i,n)cin>>v[i+1];
    n++;
    vvvi dp(n,vvi(n,vi(k+1,inf)));
    //dp[0][0][0]=v[0];
    rep(i,n){
        rep(j,i+1){
            rep(l,k+1){
                if(i==j){
                    if(j<=k&&l==j)chmin(dp[i][j][l],v[j]);
                    //if(i)chmin(dp[i][j][l],dp[i-1][j-1][l]+max((ll)(0),v[i]-v[j-1]));
                    rep(from,j)if(l>=i-from-1)chmin(dp[i][j][l],dp[from][from][l-(i-from-1)]+max((ll)(0),v[i]-v[from]));
                }
                else if(l&&i)chmin(dp[i][j][l],dp[i-1][j][l-1]);
            }
        }
    }
    /*rep(i,n){
        outvvi(dp[i]);
        cout<<endl;
    }*/
    ll ans=inf;
    rep(j,n)rep(l,k+1)chmin(ans,dp[n-1][j][l]);
    cout<<ans<<endl;
}
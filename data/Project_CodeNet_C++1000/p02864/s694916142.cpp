#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[305][305][305];//みている場所,スキップ、最後にみたindex場所
int main(){
    for(int i=0;i<305;i++)for(int j=0;j<305;j++)for(int k=0;k<305;k++)dp[i][j][k]=inf;
    ll n,d;
    cin>>n>>d;
    V<ll> a(n+1,0);
    for(int i=0;i<n;i++)cin>>a[i+1];
    dp[0][0][0]=0;
    n++;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                chmin(dp[i+1][j][i],dp[i][j][k]+max(0ll,a[i]-a[k]));
                chmin(dp[i+1][j+1][k],dp[i][j][k]);
            }
        }
    }
    ll ans=inf;
    for(int i=0;i<n;i++)for(int j=0;j<=d;j++)chmin(ans,dp[n][j][i]);
    cout<<ans<<"\n";

}
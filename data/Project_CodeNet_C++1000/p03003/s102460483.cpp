#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef unsigned  uint;
typedef unsigned long long int ull;
typedef pair<ll,ll> P;
typedef pair<P,long double> Pi;
typedef pair <long double,int> Pd;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//const uint mod=998244353;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[5000][5000],sum[5000][5000];
int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;
vector<int> a(n+1,0),b(m+1,0);
for(int i=0;i<n;i++)cin>>a[i+1];
for(int i=0;i<m;i++)cin>>b[i+1];
dp[0][0]=1;
for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
        if(i!=0&&j!=0&&a[i]==b[j]){
            (dp[i+1][j+1]+=sum[i][j]+dp[i][j])%=mod;
        }
           (dp[i+1][j]+=dp[i][j])%=mod;
           (sum[i][j+1]+=(sum[i][j]+dp[i][j]))%mod;
    }
    (dp[i+1][m+1]+=dp[i][m+1])%=mod;
}
ll ans=0;
for(int i=0;i<=m+1;i++){
    ans+=dp[n+1][i];
    ans%=mod;
}
cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define dd long double
#define mod 1000000007
const ll N=2e3+10;
ll dp[N];
ll ans(ll n){
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n==0){
        return 1;
    }
    ll sum=0;
    for(ll i=3;i<=n;i++){
        if(n-i==0 || n-i>=3){
            sum=(sum+ans(n-i))%mod;
        }
    }
    return dp[n]=sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    REP(i,N){
        dp[i]=-1;
    }
    ll n;
    cin>>n;
    cout<<ans(n)<<endl;
}

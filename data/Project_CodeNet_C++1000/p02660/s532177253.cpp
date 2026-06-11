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
const ll N=2e6+10;
ll dp[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[0]=0;
    for(ll i=1;i<N;i++){
        dp[i]=dp[i-1]+i;
    }
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=2;i*i<=n;i++){
        ll temp=0;
        if(n%i==0){
            while(n%i==0){
                temp++;
                n/=i;
            }
            ll x=upper_bound(dp,dp+N,temp)-dp;
            x--;
            ans+=x;
        }

    }
    if(n>1){
        ans++;
    }
    cout<<ans<<endl;
}

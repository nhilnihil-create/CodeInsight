#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n,k;
ll cnt[100001];
const int mod=1000000007;
ll modpow(ll x,ll n,ll mod){
    ll res=1;
    while(n>0){if(n&1) res=res*x%mod;x=x*x%mod;n>>=1;}
    return res;
}
int main(){
    cin>>n>>k;
    ll ans=0;
    for(int i=k;i>=1;--i){
        ll cur=modpow(k/i,n,mod);
        for(int j=2*i;j<=k;j+=i){
            cur=cur+mod-cnt[j];
            cur%=mod;
        }
        cnt[i]=cur;
        cur*=i;cur%=mod;
        ans+=cur;ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
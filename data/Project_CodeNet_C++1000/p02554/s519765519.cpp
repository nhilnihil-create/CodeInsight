#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

const ll mod=1e9+7;
ll qmi(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
int main(){
    ll n;
    scanf("%lld",&n);
    if(n==1) printf("0");
    else {
        ll ans=1;
        ans=((qmi(10,n,mod)-2*qmi(9,n,mod)%mod+qmi(8,n,mod))%mod+mod)%mod;
        printf("%lld",ans);
    }
}

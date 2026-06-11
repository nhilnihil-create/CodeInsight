#include <cstdio>
#include <algorithm>

using namespace std;

int N,A,B;
typedef long long int ll;

const ll MOD=1000000007;

ll fast_power(ll base,ll exp){
    if (exp==0) return 1ll;

    auto temp=fast_power(base,exp/2);
    if (exp%2) return temp*temp%MOD*base%MOD;
    else return temp*temp%MOD;
}

ll inv(ll a){ return fast_power(a,MOD-2);};

ll C(ll m,ll n){
    auto limit=min(n,m-n);

    auto denom=1ll,nom=1ll;
    for(ll i=0;i<limit;i++) denom=denom*(m-i)%MOD,nom=nom*(1+i)%MOD;

    return denom*inv(nom)%MOD;
}

int main(){

    scanf("%d%d%d",&N,&A,&B);

    auto ans=fast_power(2,N);

    ans=(ans+MOD-1)%MOD;

    ans=(ans+MOD-C(N,A))%MOD;
    ans=(ans+MOD-C(N,B))%MOD;

    printf("%lld\n",ans);

    return 0;
}
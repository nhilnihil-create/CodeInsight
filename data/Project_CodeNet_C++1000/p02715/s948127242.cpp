#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
const ll MOD=1e9+7;
const int MAXN=1e5+10;
int N,K;
ll cnt[MAXN];
void read()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K;
}
ll qpow(ll n,ll t)
{
    ll acc=1;
    while(t){
        if(t&1)acc=(acc*n)%MOD;
        n=n*n%MOD;
        t>>=1;
    }
    return acc;
}
void solve()
{
    read();
    for(int u=1;u<=K;u++){
        cnt[u]=qpow(K/u,N);
    }
    ll ans=0;
    for(int u=K;u>=1;u--){
        int t=u+u;
        while(t<=K){
            cnt[u]=(cnt[u]-cnt[t]+MOD)%MOD;
            t=t+u;
        }
        ans=(ans+cnt[u]*u%MOD)%MOD;
    }
    cout<<ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}
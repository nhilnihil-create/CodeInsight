//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,k,ans=0; cin>>n>>k;
    vector<ll> p(k+1,1),c(k+1,0);
    for(ll i=1;i<=k;i++){
        ll cnt=i;
        rep(j,20){
            if(n&(1<<j)) p[i]=(p[i]*cnt)%MOD;
            cnt=(cnt*cnt)%MOD;
        }
    }
    for(ll i=k;i>=1;i--){
        ll m=k/i; c[i]=p[m];
        for(ll j=k/i*i;j>i;j-=i)
        c[i]=(c[i]-c[j]+MOD)%MOD;
        ans=(ans+c[i]*i)%MOD;
    }
    cout<<ans<<endl;
}
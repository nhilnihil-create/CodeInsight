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
    vector<ll> a(n,0);
    rep(i,n) cin>>a[i];
    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            if(a[i]>a[j]) ans++;
        }
    }
    ans=(ans*k)%MOD;
    ll cnt=0,K=k*(k-1)/2%MOD;
    sort(al(a));
    rep(i,n){
        if(i==0) continue;
        if(a[i-1]==a[i]) cnt++;
        else cnt=0;
        ans=(ans+K*(i-cnt))%MOD;
    }
    cout<<ans<<endl;
}
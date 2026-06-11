#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;++i){
        ans+=i*(n+1-i);
    }
    rep(i,n-1){
        ll u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        ans-=u*(n-v+1);
    }
    cout<<ans<<endl;
}

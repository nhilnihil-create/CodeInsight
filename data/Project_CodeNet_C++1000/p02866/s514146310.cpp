#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 998244353
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

ll modpow(ll x,ll n){
    ll ret=1;
    while(n>0){
        if(n&1) ret=ret*x%mod;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x=x*x%mod;
        n>>=1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    ll n;cin>>n;
    vector<ll> d(n);
    rep(i,n) cin>>d[i];
    vector<ll> hm(100010,0);//距離ごとに個数を調べる
    
    if(d[0]!=0){
        cout<<0<<endl;
        return 0;
    }

    sort(d.begin(),d.end());
    
    rep(i,n){
        if(i!=0 && d[i]==0){
            cout<<0<<endl;
            return 0;
        }
    }
    rep(i,n-1){
        if(d[i+1]-d[i]>1){
            cout<<0<<endl;
            return 0;
        }
    }


    rep(i,n){//count
        hm[d[i]]++;
    }

    ll ans=1;
    rep(i,100001){
        if(hm[i+1]==0) break;
    
        ans*=modpow(hm[i],hm[i+1]);
        ans%=mod;
    }

    cout<<ans<<endl;
    return 0;
}
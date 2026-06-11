#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n),dp(1e6,-1);
    map<ll,ll> dat;

    rep(i,n){
        cin>>a[i];
        dat[a[i]]++;
    }


    ll sum=0;
    for(auto p:dat){
        sum+=(p.second)*(p.second-1)/2;
    }


    rep(i,n){
        ll t=dat[a[i]];
        ll ans=sum;
        ans-=t*(t-1)/2;
        t--;
        ans+=t*(t-1)/2;
        cout<<ans<<endl;
    }
}
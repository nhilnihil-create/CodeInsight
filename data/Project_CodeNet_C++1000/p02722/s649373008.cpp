#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll ans=0;

    vector<pair<ll,ll>> g;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i!=1){
                ll res=i;
                while(n%res==0){
                    res*=i;
                }
                g.pb({i,res/i});
            }
            if(i*i!=n) g.pb({n/i,n/i});
        }
    }

    for(ll i=1;i<=sqrt(n-1);i++){
        if((n-1)%i==0){
            ans+=2;
            if(i*i==(n-1)) ans--;
        }
    }
    ans--;

    rep(i,g.size()){
        ll x=n/g[i].second;
        ll y=g[i].first;
        if(x%y==1) ans++;
    }

    cout<<ans<<endl;
}
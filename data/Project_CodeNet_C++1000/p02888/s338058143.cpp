#include <bits/stdc++.h>
#define rep(i, n)	for(ll i=0;i<(ll)(n);i++)
using namespace std;
using ll=long long;

int main(){
    ll n;
    cin>>n;
    vector<ll> l(n);
    ll maxh=0;
    rep(i,n) {
        cin>>l[i];
        maxh=max(maxh,l[i]);
    }
    ll ans=n*(n-1)*(n-2)/6;
    sort(l.begin(),l.end());
    //cout<<l[0]<<endl;
    for(ll i=0;i<n-2;i++){
        for(ll j=i+1;j<n-1;j++){
            for(ll k=j+1;k<n;k++){
                if(l[i]+l[j]<=l[k]){
                    ans-=n-k;
                    //tmp=k;
                    //cout<<ans<<endl;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    vector<ll> l(n);
    rep(i,n) cin>>l[i];
    ll ans=0;
    rep(i,n){
        for(ll j=i+1;j<n;j++){
            for(ll k=j+1;k<n;k++){
                if(l[i]>abs(l[j]-l[k])&&l[i]<l[j]+l[k]&&l[i]!=l[j]&&l[j]!=l[k]&&l[k]!=l[i]) ans++; 
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
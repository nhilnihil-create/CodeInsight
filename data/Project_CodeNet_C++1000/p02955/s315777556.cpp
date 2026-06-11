#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    ll res=1;
    for(ll ii=1; ii*ii<=sum; ii++){
        if(sum%ii!=0) continue;
        for(ll i: {ii, sum/ii}){
            vector<ll> amari(n);
            ll wa=0;
            rep(j,n){
                amari[j]=a[j]%i;
                wa+=amari[j];
            }
            sort(amari.begin(), amari.end(), greater<ll>());
            wa/=i;
            ll tmp=0;
            rep(j,wa){
                tmp+=i-amari[j];
            }
            if(tmp<=k){
                chmax(res,i);
                if(i==sum/ii){
                    cout<<res<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
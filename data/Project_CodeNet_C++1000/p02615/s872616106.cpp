#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

int main(void){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.rbegin(),a.rend());
    ll ans=a[0];
    ll i=0;
    ll times=n-2;
    for(i=1;i<n;i++){
        for(int j=0;j<2;j++){
            if(times>0){
                ans+=a[i];
                times--;
            }
        }
    }
    cout<<ans<<endl;
}
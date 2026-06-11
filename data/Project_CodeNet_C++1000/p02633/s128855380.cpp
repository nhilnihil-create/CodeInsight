#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll x;
    cin>>x;
    ll k=0,ans=0;
    rep(0,i,(ll)1e7){
        k+=x;
        if(k%360==0){
            ans=i+1;
            cout<<ans;
            return 0;
        }
    }
}
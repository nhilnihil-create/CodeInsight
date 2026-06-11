#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

ll MOD =1e9+7;

int main(){
    ll n;
    cin>>n;
    
    ll ans,a10=1,a9=1,a8=1;

    if(n==1)ans=0;
    else{
        rep(i,n){
            a10=a10*10%MOD;
            a9=a9*9%MOD;
            a8=a8*8%MOD;
        }
        ans=(a10-a9*2+a8)%MOD;
        if(ans<0)ans+=MOD;
    }
    cout<<ans<<endl;
}
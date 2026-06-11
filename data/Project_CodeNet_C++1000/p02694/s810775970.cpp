#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    ll X;cin>>X;
    ll money=100;
    int ans=0;

    rep(i,10000){
        money+=money/100;
        
        ans++;
        if(money>=X) break;
    }
   
    cout<<ans<<endl;
}


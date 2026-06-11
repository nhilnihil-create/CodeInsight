// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    ll n, k, d;
    cin>>n>>k>>d;
    // ll sign = -1*(ans<0);
    n = abs(n);
    // if(abs(n) > d){
    //     ll ans = abs(n) - k*d;  
    //     cout<<ans;
    //     return ;
    // }
    ll times = n/d;
    if(times > k){
        cout<<n-k*d;
        return ;
    }
    ll pos = n-times*d;
    if((k-times)&1)
        cout<<abs(pos-d);
    else
        cout<<pos;

}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}
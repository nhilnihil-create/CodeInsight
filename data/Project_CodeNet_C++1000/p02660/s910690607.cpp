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
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            // ++ans;
            ll cnt = 0;
            while(n%i == 0){
                n /= i;
                ++cnt;
            }
            ll maybe = sqrt(2*cnt);
            if((maybe+2)*(maybe+1) <= cnt*2)
                ans += maybe+1;
            else if(maybe*(maybe+1) <= cnt*2)
                ans += maybe;
            else
                ans += maybe-1;
        }
    }
    if(n != 1)
        ++ans;
    cout<<ans;
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

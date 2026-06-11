// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    ll n, m;
    cin>>n>>m;
    ll f = 1, s = n;
    bool ok = false;
    if(n&1){
        ll cur = 0;
        while(m--){
            cout<<f<<" "<<s<<"\n";
            ++f, --s;
        }
    }
    else{
        while(m--){
            cout<<f<<" "<<s<<"\n";
            ++f, --s;
            if(s-f <= n/2&& !ok)
                --s, ok = true;
        }
    }
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
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
ll val(ll num){
    return num*num*num*num*num;
}
void solve(){
    ll x;
    cin>>x;
    for(ll i = -200; i < 200; i++)
        for(ll j = -200; j < 200; j++){
            if(val(i) - val(j) == x){
                cout<<i<<" "<<j<<"\n";
                return ;
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
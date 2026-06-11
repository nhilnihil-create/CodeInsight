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
    vector<ll> vec(n);
    ll ans = 1;
    for(int i = 0; i < n; i++){
        cin>>vec[i];
        if(vec[i] == 0){
            cout<<"0";
            return ;
        }
    }
    sort(vec.begin(), vec.end());
    for(ll k : vec){
        if(ans > INF/k){
            cout<<-1;
            return ;
        }
        ans *= k;
    }
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
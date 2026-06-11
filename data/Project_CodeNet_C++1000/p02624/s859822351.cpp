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
    vector<ll> vec(n+1, 2);
    for(ll i = 2; i*i <= n; i++)
        for(ll j = i*i; j <= n; j += i)
            if(i != j/i)
                vec[j] += 2;
            else
                vec[j] += 1;

    ll ans= 1;
    // cout<<vec[4];
    for(int i = 2; i <= n; i++)
        ans += i*vec[i];
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
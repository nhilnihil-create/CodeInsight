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
    int n;
    cin>>n;
    vector<ll> vec(n);
    for(int i = 0; i < n; i++)
        cin>>vec[i];
    vector<ll> prefix(n), suffix(n);
    for(int i = 0; i < n; i++){
        if(i)
            prefix[i] = prefix[i-1];
        prefix[i] ^= vec[i];
    }
    for(int i = n-1; i >= 0; i--){
        if(i != n-1)
            suffix[i] = suffix[i+1];
        suffix[i] ^= vec[i];
    }
    for(int i = 0; i < n; i++){
        ll ans = 0;
        if(i)
            ans ^= prefix[i]^vec[i];
        if(n-1-i)
            ans ^= suffix[i]^vec[i];
        cout<<ans<<" ";
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
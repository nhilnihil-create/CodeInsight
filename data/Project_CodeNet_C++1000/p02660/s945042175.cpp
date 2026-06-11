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
ll calc(ll n){
    for(ll i = 2; ;i++)
        if(i*(i+1)/2 > n)
            return i-1;
}
void solve(){
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n%i == 0){
            n /= i;
            ++cnt;
        }
        if(cnt == 0)
            continue;
        ans += calc(cnt);
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
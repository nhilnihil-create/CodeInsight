#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000; 

int main(){
    ll n;
    cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll ans = 0;
    map<ll,ll> mp;
    rep(i,n){
        ll b = i+a[i];
        ll c = i-a[i];
        if(mp.count(c)){
        ans+=mp.at(c);
        }
        
        if(mp.count(b)){
            mp[b]++;
        }
        else{
            mp[b] = 1;
        }
    }
    //cout << mp.at(0) << endl;
    cout << ans << endl;
}
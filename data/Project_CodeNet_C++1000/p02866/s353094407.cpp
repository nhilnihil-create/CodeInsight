#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll num = 998244353;

//繰り返し二乗法
ll ex(ll x,ll n){
    if(n==0)return 1;
    else if(n%2==1)return ex(x,n-1)*x%num;
    else return ex(x*x%num,n/2)%num;
};

int main(){
    ll n;
    cin >> n;
    vector<ll> d(n);
    unordered_map<ll,ll> mp;
    ll ans = 1;
    ll mx = 0;
    for(ll i = 0; i < n; i++){
        cin >> d[i];
        if(d[i] > mx) mx = d[i];
    }
    for(ll i = 0; i < n; i++) mp[d[i]]++;
    for(ll i = 1; i < mx; i++){
        ans *= ex(mp[i],mp[i+1]);
        ans %= num;
    }
    if(d[0] != 0 || mp[0] > 1) ans = 0;
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
string L;
vector<int> on;

ll exp(ll x, ll y){
    if(y == 0) return 1;
    
    ll e = exp(x, y / 2) % mod;
    e = e * e % mod;
    if(y % 2 == 1) e = e * x % mod;
    return e;
}

int main(){
    cin >> L;
    reverse(L.begin(), L.end());
    for(int i = 0; i < L.size(); i++){
        if(L[i] == '1') on.push_back(i);
    }
    ll ans = exp(2, on.size());
    for(int i = 0; i < on.size(); i++){
        ll res1 = exp(2, (int)on.size() - i - 1);
        ll res2 = exp(3, on[i]);
        ans += res1 * res2 % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
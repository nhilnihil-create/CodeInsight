#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    ll n, p;
    string s;
    cin >> n >> p >> s;
    
    if(p == 2 || p == 5){
        ll ans = 0;
        rep(i,n){
            if((int)(s[i] - '0') % p == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }

    vector<ll> sum(n+1, 0), ten(n+1, 1);
    for(int i = n-1; i >= 0; i--){
        ten[i] = ten[i+1] * 10 % p;
    }
    for(int i = n-1; i >= 0; i--){
        sum[i] = ((ll)(s[i] - '0') * ten[i+1] % p + sum[i+1]) % p;
    }
    map<ll,ll> m;
    for(auto i : sum){
        m[i]++;
    }
    ll ans = 0;
    for(auto i : m){
        ans += i.second * (i.second - 1) / 2;
    }
    cout << ans << endl;
}
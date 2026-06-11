#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 1e9+7;

ll mypow(ll x, ll n){
        ll result = 1;
        for(ll i = 0; i < n; i++){
                result = result * x % M;
        }
        return result % M;
}

int main(void){
        ll n;
        cin >> n;
        ll ans = (mypow(10, n) - mypow(9, n) * 2 + mypow(8, n)) % M;
        if(ans < 0) ans += M;
        cout << ans << endl;
        return 0;
}

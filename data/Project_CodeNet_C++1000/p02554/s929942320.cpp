#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1000000007;

ll power(ll x, ll y){
    ll ret = 1;

    for(int i = 1; i <= y; i++)
        ret = ret*x%mod;

    return ret;
}

int main(){
    ll n;
    cin >> n;

    ll ans = power(10,n) - 2*power(9,n) + power(8,n);

    ans%=mod;

    ans = (ans + mod)%mod;

    cout << ans << endl;

    return 0;
}
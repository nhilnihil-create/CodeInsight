#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll fast_pow(ll a, ll b){
    if(b == 0) return 1;
    a = a % MOD;
    ll t=fast_pow(a,b/2)%MOD;
    t=t*t%MOD;
    if(b&1)t=t*a%MOD;
    return t;
}

int main()
{
    ll N;
    cin >> N;

    ll ans = 0;

    ans += fast_pow(10, N);
    ans -= 2 * fast_pow(9, N);
    ans %= MOD;
    if(ans < 0) ans += MOD;
    ans += fast_pow(8, N);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}
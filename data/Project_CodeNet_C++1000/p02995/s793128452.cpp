#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll gcd(ll a, ll b){
    if (b == 0){
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ac = (a+c-1)/c;
    ll ad = (a+d-1)/d;
    ll cd_gcd = gcd(c, d);
    ll aab = (a+c*d/cd_gcd-1)/(c*d/cd_gcd);

    ll bc = b/c;
    ll bd = b/d;
    ll bab = b/(c*d/cd_gcd);

    ll c_num = max(bc - ac+1, ll(0));
    ll d_num = max(bd - ad+1, ll(0));
    ll cd_num = max(bab - aab+1, ll(0));

    ll sum = b - a + 1;

    ll ans = sum - (c_num + d_num - cd_num);

    cout << ans << endl;

    return 0;
}

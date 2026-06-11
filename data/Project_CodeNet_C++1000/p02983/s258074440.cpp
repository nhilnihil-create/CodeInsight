#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll L, R;
    cin >> L >> R;

    ll ans = LLONG_MAX;
    ll maxL = min(L+2019, R);
    for(ll i=L;i<=maxL;i++){
        for(ll j=i+1;j<=maxL;j++){
            ans = min(ans, i*j%2019);
        }
    }

    cout << ans << endl;

    return 0;
}

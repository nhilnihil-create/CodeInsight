#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

ll cal(ll k){
    ll sum = 0;
    for (ll i = 1; i <= k; ++i)
    {
        sum += i;
    }
    if(k <= 0) return 0;
    else return sum;
}

int main() {

    ll n; cin >> n;
    ll ans = 0;

    rep(i,n) ans += i;

    cout << ans;


    return 0;
}










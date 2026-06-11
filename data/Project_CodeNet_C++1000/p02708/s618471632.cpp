#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

typedef long long ll;

int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int N,K; cin >> N >> K;

    ll res = 0;
    for (ll i = K; i <= N+1; ++i) {
        ll comb = ((N+1-i)*i+1)%MOD;
        res = (res+comb)%MOD;
    }

    cout << res << "\n";

}

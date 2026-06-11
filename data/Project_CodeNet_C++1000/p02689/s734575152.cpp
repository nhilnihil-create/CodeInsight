#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    vector<set<ll>> mat(n, set<ll>());
    rep(i, n){
        cin >> h[i];
    }
    rep(i, m){
        ll a, b;
        cin >> a >> b;
        mat[a-1].insert(b-1);
        mat[b-1].insert(a-1);
    }

    ll ans = 0;
    rep(i, n){
        bool flg = true;
        for(auto& other : mat[i]) {
            if (h[i] <= h[other] ) {
                flg = false;
                break;
            }
        }
        if (flg){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

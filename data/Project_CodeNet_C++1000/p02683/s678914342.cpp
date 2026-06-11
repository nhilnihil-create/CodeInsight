#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n, m, x;
    cin >> n >> m >> x;

    vector<vector<ll>> a(n, vector<ll>(m+1));
    rep(i, n){
        cin >> a[i][0];
        rep(j, m){
            cin >> a[i][j+1];
        }
    }

    ll min_cc = LLONG_MAX;

    for (ll i=0;i<(1<<n);i++){
        vector<ll> aa(m, 0);
        ll cc = 0;
        for(ll j=0;j<n;j++){
            if (i & (1 << j)){
                cc += a[j][0];
                rep(jj, m){
                    aa[jj] += a[j][jj+1];
                }
            }
        }

        bool flg = true;
        rep(jj, m){
            if (aa[jj] < x) {
                flg = false;
            }
        }

        if (flg){
            min_cc = min(min_cc, cc);
        }
    }


    if (min_cc == LLONG_MAX){
        cout << -1 << endl;
    }else{
        cout << min_cc << endl;
    }
}

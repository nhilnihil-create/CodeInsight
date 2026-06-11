#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    ll k, q;
    cin >> k >> q;
    vector<ll> d(k);
    REP(i, k){
        cin >> d.at(i);
    }

    REP(i, q){
        ll n, x, m;
        cin >> n >> x >> m;
        ll ans = n - 1;
        ll last = x;
        REP(j, k){
            const ll dj = d.at(j) % m;
            const ll num = max(0LL, (n - 1 - j + k - 1) / k);
            last += dj * num;
            if(dj == 0){
                ans -= num;
            }
        }
        ans -= last / m - x / m;
        cout << ans << endl;
    }
    return 0;
}

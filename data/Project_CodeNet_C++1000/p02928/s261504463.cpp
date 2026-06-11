#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, n) for (ll i = n-1; i >= 0; i--)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repd2(i, s, n) for (ll i = n-1; i >= (s); i--)


int main() {
    const int MOD = 1000000007;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    rep(i, n) cin >> a[i];

    ll cnt = 0;
    rep(i, n) {
        rep2(j, i+1, n) {
            if (a[i] > a[j]) cnt ++;           
        }
    }


    ll choose = 0;
    rep(i, n) {
        rep(j, n) {
            if (a[i] > a[j]) choose++;
        }
    }

    ll ans = cnt * k;
    ans += ((k*(k-1)/2)%MOD) * choose;
    ans %= MOD;
    
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    ll l, r;
    cin >> l >> r;
    ll jmax = min(l + 2020, r);

    ll ans = 2018;

    for(ll i = l; i <= jmax - 1; i++){
        for(ll j = i + 1; j <= jmax; j++){
            ans = min((i * j) % 2019, ans);
        }
    }
    cout << ans << endl;
    return 0;
}

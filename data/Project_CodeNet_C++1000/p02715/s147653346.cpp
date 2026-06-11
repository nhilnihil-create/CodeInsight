/* Author: Rennan Rocha
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>

#define INF 1e18
#define MOD 1000000007

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order(); order_of_key();

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll sub(ll a, ll b) {
    ll aux = ((a % MOD) - (b % MOD)) % MOD;
    if(aux < 0) aux += MOD;
    return aux;
}

ll add(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll expMod(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b & 1LL) return mul(a, expMod(a, b-1));
    ll aux = expMod(a, b/2LL);
    return mul(aux, aux);
}

int main() {
    ios_base::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    ll resp[k+1];
    for(ll i = k; i >= 1; i--) {
        ll contrib = expMod(k/i, n);
        for(ll j = 2; j * i <= k; j++) {
            contrib = sub(contrib, resp[i*j]);
        }
        resp[i] = contrib;
        contrib = mul(i, contrib);
        ans = add(ans, contrib);
    }
    cout << ans << "\n";
}

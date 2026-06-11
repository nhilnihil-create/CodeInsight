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

ll n, p;
string s;
ll mul(ll a, ll b) {
    return ((a % p) * (b % p)) % p;
}

ll expMod(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b & 1LL) return mul(a, expMod(a, b-1));
    ll aux = expMod(a, b/2);
    return mul(aux, aux);
}

ll add(ll a, ll b) {
    return ((a % p) + (b % p)) % p;
}

void solve_esp(int x) {
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if((s[i] - '0') % x == 0) ans += i+1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    cin >> s;

    if(p == 2 || p == 5) {
        solve_esp(p);
        return 0;
    }

    int pref[n];
    int suf[n];
    pref[0] = (s[0] - '0') % p;
    suf[n-1] = (s.back() - '0') % p;
    map<ll,ll> sufm;
    sufm[0]++;
    ll ans = 0;
    ans += sufm[suf[n-1]];
    sufm[suf[n-1]]++;
    for(int i = 1; i < n; i++) {
        pref[i] = (pref[i-1] + (s[i] - '0')) % p;
        suf[n-i-1] = add(mul(s[n-i-1] - '0', expMod(10, i)), suf[n-i]);
        ans += sufm[suf[n-i-1]];
        //cout << "i: " << i << " add: " << sufm[suf[n-i-1]] << endl;
        sufm[suf[n-i-1]]++;
    }
    cout << ans << endl;
}

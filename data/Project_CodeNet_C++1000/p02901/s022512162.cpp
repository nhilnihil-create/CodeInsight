#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define quick                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define time cerr << (0.1 * clock()) / CLOCKS_PER_SEC << endl;
#define mod 1000000007
typedef long long ll;
typedef pair<ll, ll> pl;
#define forn(n) for (ll i = 0; i < ll(n); i++)

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(m, {0, 0});
    vector<ll> maxi((1 << n) + 5, 1e15);
    forn(m) {
        int a, b;
        cin >> a >> b;
        v[i].ff = a;
        for (int j = 0; j < b; ++j) {
            int x;
            cin >> x;
            v[i].ss |= (1 << (x - 1));
        }
        for (int j = 0; j < (1 << n); ++j) {
            if (maxi[j] != -1) {
                maxi[j | v[i].ss] = min(maxi[j | v[i].ss], maxi[j] + v[i].ff);
            }
        }
        maxi[v[i].ss] = min(maxi[v[i].ss], v[i].ff);
    }
    cout << (maxi[(1 << n) - 1] == 1e15 ? -1 : maxi[(1 << n) - 1]) << '\n';
}

int main() {
    quick;
    solve();
    // ll t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
}
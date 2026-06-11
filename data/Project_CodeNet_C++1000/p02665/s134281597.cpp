#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }

const int maxn = 2e5 + 7;
const ll inf = 1e18;

vector<ll> v(maxn);
vector<ll> mostposs(maxn);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        cin >> v[i];
    }

    if (n == 0) {
        if (v[0] != 1) out(-1);
        out(1);
    }

    ll activep = 1LL;
    for (int i = 0; i <= n; i++) {
        if (v[i] > activep) out(-1);
        activep -= v[i];
        if (activep <= inf/2LL) activep *= 2LL;
    }

    if (v[0] > 0) {
        out(-1);
    }

    for (int i = n; i >= 0; i--) {
        mostposs[i] = v[i] + mostposs[i+1];
    }

    activep = 1LL;
    ll ans = 1LL;
    for (int i = 1; i <= n; i++) {
        activep *= 2LL;
        if (v[i] > activep) out(-1);
        ans += v[i]; // add leaves
        activep -= v[i]; // minus leaves bc they can't be parents to next level
        activep = min(mostposs[i+1],activep); // bound # of node that will be parents to next level
        ans += activep; // add parents of this level
    }
    
    out(ans);
    
    return 0;
}

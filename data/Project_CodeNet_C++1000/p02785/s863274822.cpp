#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define INF (1 << 29)
const int mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> h(n);
    for(ll i = 0; i < n; i++) {
        cin >> h[i];
    }
    dsort(h, ll);

    ll ans = 0;
    for(ll i = k; i < n; i++) {
        ans += h[i];
    }
    cout << ans << endl;
    return 0;
}
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
    ll n, k, p;
    double max_e = 0.0;
    double e[200005];
    m0(e);
    cin >> n >> k;

    for(ll i = 1; i <= n; i++) {
        cin >> p;
        e[i] = e[i - 1];
        for(ll j = 1; j <= p; j++) {
            e[i] += (double)j / p;
        }
    }

    for (ll i = k; i <= n; i++) {
        double now = e[i] - e[i - k];
        max_e = max(max_e, now);
    }

    printf("%.10f\n", max_e);
    return 0;
}
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
    ll n;
    ll p[200005];
    cin >> n;

    ll ans = 0;
    ll min_ = INF;
    for(ll i = 0; i < n; i++) {
        cin >> p[i];
        if(min_ > p[i]) {
            min_ = p[i];
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
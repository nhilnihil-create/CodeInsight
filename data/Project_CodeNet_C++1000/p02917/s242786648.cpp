#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define dump(x) cout << #x << " = " << (x) << endl
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl

const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll b[105];
    for(int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(i == 0) {
            ans += b[i];
        } else {
            ans += min(b[i], b[i - 1]);
        }
    }
    ans += b[n - 2];
    cout << ans << endl;

    return 0;
}
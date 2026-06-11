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
    ll a, b, k;
    cin >> a >> b >> k;
    if(a >= k) {
        a -= k;
    } else {
        k -= a;
        a = 0;
        if(b >= k) {
            b -= k;
        } else {
            b = 0;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
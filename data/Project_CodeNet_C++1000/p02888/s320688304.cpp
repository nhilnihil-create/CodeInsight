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
const int mod = 1000000007;

int main() {
    ll n;
    cin >> n;

    vector<ll> l(n);
    for(ll i = 0; i < n; i++) {
        cin >> l[i];
    }
    asort(l);

    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j < n; j++) {
            ll k = lower_bound(l.begin(), l.end(), l[i] + l[j]) - l.begin();
            cnt += k - (j + 1);
        }
    }

    cout << cnt << endl;
    return 0;
}
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

ll modpow(ll x, ll n) {
    if(n == 0)
        return 1;
    ll res = modpow(x * x, n / 2);
    if(n & 1)
        res = res * x;
    return res;
}

int main() {
    ll h;
    cin >> h;
    ll cnt = 0;
    while(true) {
        if(h == 1) {
            break;
        }
        h /= 2;
        cnt++;
    }
    cout << 2 * modpow(2, cnt) - 1 << endl;
    return 0;
}
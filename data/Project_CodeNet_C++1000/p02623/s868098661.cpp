#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n+1, LINF), b(m+1, LINF);
    a[0] = 0;
    b[0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i+1];
        b[i+1] += b[i];
    }

    ll res = 0;
    for (int i = 0; i < n + 1; ++i) {
        ll rem = k - a[i];
        if (rem < 0) break;
        res = max(res, i + (ll)(upper_bound(b.begin(), b.end(), rem) - b.begin()) - 1);
    }
    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int k, q;
vector<int> d, n, x, m;


void input() {
    cin >> k >> q;
    d = vector<int>(k);
    n = x = m = vector<int>(q);
    rep(i, k) cin >> d[i];
    rep(i, q) cin >> n[i] >> x[i] >> m[i];
}


ll query(int i) {
    vector<ll> sd(k + 1, 0);
    vector<int> zn(k + 1, 0);
    rep(j, k) {
        sd[j+1] = sd[j] + d[j] % m[i];
        if (d[j] % m[i] == 0) {
            zn[j+1] = zn[j] + 1;
        } else {
            zn[j+1] = zn[j];
        }
    }
    int nn = (n[i] - 1) / k;
    ll a = x[i] % m[i];
    ll b = a + sd.back() * nn;
    b += sd[(n[i] - 1) % k] ;
    ll ans = n[i] - 1;
    ans -= b / m[i];
    ans -= zn.back() * nn + zn[(n[i] - 1) % k];
    return ans;
}


int main() {
    input();
    rep(i, q) cout << query(i) << endl;
}

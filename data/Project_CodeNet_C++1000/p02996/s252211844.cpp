#include <bits/stdc++.h>
#define rep(i,n) for (long long int i = 0; i < (long long int)(n); i++)
using namespace std;
using ll = long long int;
using P = pair<ll,ll>;
const ll MOD = 1e9+7;

int main() {
    ll n;
    cin >> n;
    vector<P> v(n);
    rep(i,n) {
        ll a, b;
        cin >> a >> b;
        v[i] = {b,a};
    }
    sort(v.begin(), v.end());
    ll s = 0;
    rep(i,n) {
        P p = v[i];
        s += p.second;
        if (s > p.first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

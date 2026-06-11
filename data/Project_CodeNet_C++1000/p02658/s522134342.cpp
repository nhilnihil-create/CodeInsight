#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);

    ll ans;
    ll p = pow(10, 18);
    rep(i, n) {
        if (a.at(i) == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll prod = 1;
    rep(i, n) {
        //ll prod = 1;
        if (a.at(i) <= p /prod) prod *= a.at(i);
        else {
            cout << -1 << endl;
            return 0;
        }
        //ans = prod;
    }

    cout << prod << endl;
    //cout << p << endl;
    return 0;
}
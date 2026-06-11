#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef unsigned long long ll;
//typedef unsigned long long ull;

int main() {
    int n;
    cin >> n;
    n++;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    vector<ll> c(n);//分岐点の最大数

    c.at(0) =  (1 - a.at(0));
//    if (c.at(0) < 0) {
    if (1 < a.at(0)) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        c.at(i) = 2 * (c.at(i - 1) - a.at(i - 1));
//        if (c.at(i) < 0) {
        if (2*(c.at(i-1)-a.at(i-1)) < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<ll> b(n);

    for (int i = n - 2; i >= 0; i--) {
        ll ab = a.at(i + 1) + b.at(i + 1);
        if(c.at(i) < a.at(i)){
            cout << -1 << endl;
            return 0;
        }
        ll ca = c.at(i) - a.at(i);
        if (ab <= ca) {
            b.at(i) = ab;
        } else if (ab <= 2 * ca) {
            b.at(i) = ca;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    rep(i, n) {
        ans += b.at(i) + a.at(i);
    }
    cout << ans << endl;
    return 0;
}


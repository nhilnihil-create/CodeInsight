#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll p = (a1 - b1) * t1;
    ll q = (a2 - b2) * t2;
    if (p > 0) {
        p *= -1;
        q *= -1;
    }
    if ((p + q) < 0) {
        cout << 0 << endl;
    }
    else if ((p + q) == 0) {
        cout << "infinity" << endl;
    }
    else {
        ll s = (-1 * p) / (p + q);
        ll t = (-1 * p) % (p + q);
        if (t == 0) {
            cout << (s * 2) << endl;
        }
        else {
            cout << (s * 2 + 1) << endl;
        }
    }
    return 0;
}

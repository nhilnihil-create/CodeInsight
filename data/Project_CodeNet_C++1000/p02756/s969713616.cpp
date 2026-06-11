#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n';

string s;
int q, rev;
deque <char> d;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    rev = 0;
    cin >> s;
    rep(i, 0, (int)s.length(), 1) {
        d.pb(s[i]);
    }
    cin >> q;
    rep(i, 0, q, 1) {
        int t; cin >> t;
        if (t == 1) rev = 1 - rev;
        else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                if (rev) d.pb(c);
                else d.pf(c);
            }
            else {
                if (rev) d.pf(c);
                else d.pb(c);
            }
        }
    }
    if (rev) {
        reverse(all(d));
        for(auto it:d) {
            cout << it;
        }
    }
    else {
        for(auto it:d) {
            cout << it;
        }
    }
    time;
}
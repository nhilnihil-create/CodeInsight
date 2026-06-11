#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

using P = pair<ll, int>;
const int RED = 1;
const int GREEN = 2;
const int NONE = 3;

int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<P> p;
    ll val;
    rep(i, A) {
        cin >> val;
        p.push_back(P{val, RED});
    }

    rep(i, B) {
        cin >> val;
        p.push_back(P{val, GREEN});
    }

    rep(i, C) {
        cin >> val;
        p.push_back(P{val, NONE});
    }

    sort(p.begin(), p.end());
    vector<ll> red, green, none;
    ll ans = 0;
    rep(_, X + Y) {
        P e = p.back();
        p.pop_back();
        ans += e.first;
        if (e.second == RED) {
            red.push_back(e.first);
        } else if (e.second == GREEN) {
            green.push_back(e.first);
        } else {
            none.push_back(e.first);
        }
    }

    if (red.size() <= X && green.size() <= Y) {
        cout << ans << endl;
        return 0;
    }

    if(red.size() > X) {
        while(red.size() > X) {
            ans -= red.back();
            red.pop_back();
            while(true) {
                P e = p.back();
                p.pop_back();
                if(e.second != RED) {
                    ans += e.first;
                    break;
                }
            }
        }
    } else {
        while(green.size() > Y) {
            ans -= green.back();
            green.pop_back();
            while(true) {
                P e = p.back();
                p.pop_back();
                if(e.second != GREEN) {
                    ans += e.first;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}

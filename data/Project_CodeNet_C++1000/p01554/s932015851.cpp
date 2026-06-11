#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;
using ll = long signed long;

int main() {

    ll n; cin >> n;

    set<string> u;
    REP(i, n) {
        string ui; cin >> ui;
        u.insert(ui);
    }

    ll m; cin >> m;

    bool o = false;
    REP(i, m) {
        string ti; cin >> ti;
        bool found = u.find(ti) != u.end();
        if (found) {
            if (o) {
                cout << "Closed by " + ti << "\n";
            } else {
                cout << "Opened by " + ti << "\n";
            }
            o = !o;
        } else {
            cout << "Unknown " + ti << "\n";
        }
    }

}

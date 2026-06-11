#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int an, bn, m;
    cin >> an >> bn >> m;
    vector<int> a(an + 1);
    int am = 1e9;
    for (int i = 1; i <= an; i++) {
        cin >> a.at(i);
        am = min(am, a.at(i));
    }
    vector<int> b(bn + 1);
    int bm = 1e9;
    for (int i = 1; i <= bn; i++) {
        cin >> b.at(i);
        bm = min(bm, b.at(i));
    }
    vector<int> x(m);
    vector<int> y(m);
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> x.at(i) >> y.at(i) >> c.at(i);
    }
    int cm = 1e9;
    for (int i = 0; i < m; i++) {
        cm = min(cm, a.at(x.at(i)) + b.at(y.at(i)) - c.at(i));
    }
    cout << min(cm, am + bm) << endl;
    return 0;
}
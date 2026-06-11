#include <bits/stdc++.h>
#define sz(v) (int)v.size()
#define debug(var) cout << #var << ": " << var << endl;
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> cntrow(h + 1), cntcol(w + 1);
    set<pair<int, int>> targets;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cntrow[x]++, cntcol[y]++;
        targets.insert({x, y});
    }

    int mxcntrow = 0;
    for (int e : cntrow)
        mxcntrow = max(mxcntrow, e);
    int mxcntcol = 0;
    for (int e : cntcol)
        mxcntcol = max(mxcntcol, e);

    vector<int> rows, cols;
    for (int i = 0; i < sz(cntrow); i++) {
        int &e = cntrow[i];
        if (e == mxcntrow)
            rows.push_back(i);
    }
    for (int i = 0; i < sz(cntcol); i++) {
        int &e = cntcol[i];
        if (e == mxcntcol)
            cols.push_back(i);
    }
    int flag_perfect = 0;
    for (int ei : rows) {
        for (int ej : cols)
            if (targets.find({ei, ej}) == targets.end()) {
                flag_perfect = 1;
                break;
            }
        if (flag_perfect)
            break;
    }
    cout << mxcntrow + mxcntcol - 1 + flag_perfect;
}
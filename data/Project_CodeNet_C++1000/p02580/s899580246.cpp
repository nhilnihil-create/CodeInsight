#include <bits/stdc++.h>
using namespace std;

#define MAXD 300001
using pii = pair<int,int>;
unordered_set<int> rows[MAXD],cols[MAXD];
int h,w,m;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>h>>w>>m;
    for (int i = 0,hi,wi; i < m; ++i) {
        cin>>hi>>wi;
        rows[hi].insert(wi);
        cols[wi].insert(hi);
    }
    vector<pii> brows, bcols;
    for (int i = 1; i <= h; ++i) brows.emplace_back(rows[i].size(),i);
    for (int i = 1; i <= w; ++i) bcols.emplace_back(cols[i].size(),i);
    sort(brows.rbegin(), brows.rend());
    sort(bcols.rbegin(), bcols.rend());

    while (brows.back().first != brows.front().first) brows.pop_back();
    while (bcols.back().first != bcols.front().first) bcols.pop_back();

    for (pii r: brows) {
        for (pii c: bcols) {
            if (!rows[r.second].count(c.second)) {
                cout << brows[0].first + bcols[0].first;
                return 0;
            }
        }
    }

    cout << brows[0].first + bcols[0].first - 1;
}
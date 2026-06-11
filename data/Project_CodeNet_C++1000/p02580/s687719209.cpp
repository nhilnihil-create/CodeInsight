/**
 *    author:  FromDihPout
 *    created: 2020-08-25
**/

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, m;
    cin >> h >> w >> m;
    vector<pair<int,int>> rows(h), cols(w);
    set<pair<int,int>> targets;
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        targets.insert({r, c});
        rows[r].f++;
        rows[r].s = r;
        cols[c].f++;
        cols[c].s = c;
    }
    sort(rows.begin(), rows.end(), greater<pair<int,int>>());
    sort(cols.begin(), cols.end(), greater<pair<int,int>>());
    
    int ans = 0;
    int p1 = 0, p2 = 0;
    while (p1 < h) {
        if (rows[p1].f + cols[p2].f > ans) {
            bool extra = targets.count({rows[p1].s, cols[p2].s});
            ans = max(ans, rows[p1].f + cols[p2].f - extra);
            p2++;
            if (p2 >= w) {
                p1++;
                p2 = 0;
            }
        }
        else if (p1 + 1 >= h || rows[p1+1].f + cols[0].f <= ans) {
           break;
        }
        else {
            p1++;
            p2 = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
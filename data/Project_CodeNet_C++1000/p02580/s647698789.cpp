/*
 * @Author: Luisvacson
 * @LastEditors: Luisvacson
 * @Descriptions: None
 * @Date: 2020-09-05 19:39:07
 * @LastEditTime: 2020-09-05 19:57:47
 * @FilePath: \VSC\C++\Public\Bomber.cpp
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long

int n, m;
int bn;
pii bomb[300005];
int row[300005];
int col[300005];
set<int> st;
signed main()
{
    scanf("%d%d", &n, &m);
    scanf("%d", &bn);
    register int i;

    for (i = 1; i <= bn; ++i) {
        scanf("%d%d", &bomb[i].first, &bomb[i].second);
        ++row[bomb[i].first];
        ++col[bomb[i].second];
        st.insert(bomb[i].first*3*1e5+bomb[i].second);
    }

    int maxr = -1 << 30, maxc = -1 << 30;
    for (i = 1; i <= n; ++i)
        maxr = max(maxr, row[i]);
    for (i = 1; i <= m; ++i)
        maxc = max(maxc, col[i]);

    vector<int> Qr, Qc;
    for (i = 1; i <= n; ++i)
        if (row[i] == maxr)
            Qr.push_back(i);
    for (i = 1; i <= m; ++i)
        if (col[i] == maxc)
            Qc.push_back(i);

    for (vector<int>::iterator it = Qr.begin(); it != Qr.end(); ++it) {
        for (vector<int>::iterator jt = Qc.begin(); jt != Qc.end(); ++jt) {
            int r = *it;
            int c = *jt;
            if (st.find(r*3*1e5+c) == st.end()) {
                printf("%d\n", maxr + maxc);
                return 0;
            }
        }
    }

    printf("%d\n", maxr + maxc - 1);
    return 0;
}
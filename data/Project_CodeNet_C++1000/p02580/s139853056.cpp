#include <bits/stdc++.h>

using namespace std;

const int N = 300004;
int cnth[N], cntw[N], x[N], y[N];
map <int, bool> mp[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w, m;
    cin >> h >> w >> m;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        mp[x[i]][y[i]] = true;
        cnth[x[i]]++, cntw[y[i]]++;
    }
    int mxh = 0, mxw = 0;
    for (int i = 0; i < N; i++) {
        mxh = max(mxh, cnth[i]);
        mxw = max(mxw, cntw[i]);
    }
    vector <int> hall, wall;
    for (int i = 0; i < N; i++) {
        if (cnth[i] == mxh) {
            hall.push_back(i);
        }
        if (cntw[i] == mxw) {
            wall.push_back(i);
        }
    }
    int cnt = 0, mx = 0;
    for (int i = 0; i < hall.size(); i++) {
        for (int j = 0; j < wall.size(); j++) {
            cnt++;
            if (cnt > N * 2)
                break;
            mx = max(mx, mxh + mxw - mp[hall[i]][wall[j]]);
        }
        if (cnt > N * 2)
            break;
    }
    cout << mx;
}
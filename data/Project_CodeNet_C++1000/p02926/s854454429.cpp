#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}

int main ()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x || y) {
            a.emplace_back(x, y);
        }
    }
    long double ans = 0.0;
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < (int) a.size(); i++) {
        long double curX = 0.0, curY = 0.0;
        for (int j = 0; j < (int) a.size(); j++) {
            int ind = (i + j) % a.size();
            curX += a[ind].first;
            curY += a[ind].second;
            ans = max(ans, sqrt(curX * curX + curY * curY));
        }
    }
    cout << setprecision(15) << fixed << ans;
    return 0;
}

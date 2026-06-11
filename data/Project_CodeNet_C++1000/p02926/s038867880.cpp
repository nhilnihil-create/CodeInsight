#include <bits/stdc++.h>

#define long long long int

using namespace std;

// @author: pashka

bool cmp(const pair<long, long> &q, const pair<long, long> &w) {
    if (q == w)
        return false;
    if (q == make_pair(0ll, 0ll))
        return true;
    if (w == make_pair(0ll, 0ll))
        return false;
    bool side1 = (q.second > 0 || q.second == 0 && q.first < 0);
    bool side2 = (w.second > 0 || w.second == 0 && w.first < 0);

    if (side1 != side2) {
        return side1 < side2;
    }

    long vp = q.first * w.second - q.second * w.first;
    return vp > 0;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<long, long>> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i + n].first = -a[i].first;
        a[i + n].second = -a[i].second;
    }

    long y0 = 0;
    long x0 = 0;
    for (int i = 0; i < n; i++) {
        long x = a[i].first;
        long y = a[i].second;
        if (y > 0 || (y == 0 && x < 0)) {
            x0 += x;
            y0 += y;
        }
    }

    sort(a.begin(), a.end(), cmp);

    double res = 0;

    for (int i = 0; i < 2 * n; i++) {
        long x = a[i].first;
        long y = a[i].second;
        x0 += x;
        y0 += y;
        res = max(res, hypot(x0, y0));
    }
    cout << setprecision(20) << res;

    return 0;
}
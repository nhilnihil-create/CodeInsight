#include <bits/stdc++.h>
using namespace std;

double sqr(double a) {
    return a * a;
}

double dist(double x, double y) {
    return sqr(x) + sqr(y);
}

bool comp(pair<double, double> a, pair<double, double> b) {
    return atan2(a.first, a.second) < atan2(b.first, b.second);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<double, double> > pt(n);
    vector<double> dpx(n), dpy(n);
    for (int i = 0; i < n; i++)
        cin >> pt[i].first >> pt[i].second;

    sort(pt.begin(), pt.end(), comp);

    double ans = 0.;
    for (int i = 0; i < n; i++) {
        double x = pt[i].first, y = pt[i].second;
        ans = max(ans, sqrt(dist(x, y)));
        for (int k = 1; k < n; k++) {
            int j = (i + k) % n;
            x += pt[j].first;
            y += pt[j].second;
            ans = max(ans, sqrt(dist(x, y)));
        }
    }
    for (int i = 0; i < n; i++) {
        double x = pt[i].first, y = pt[i].second;
        ans = max(ans, sqrt(dist(x, y)));
        for (int k = 1; k < n; k++) {
            int j = (i - k) % n;
            if (j < 0)
                j += n;
            x += pt[j].first;
            y += pt[j].second;
            ans = max(ans, sqrt(dist(x, y)));
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
    return 0;
}

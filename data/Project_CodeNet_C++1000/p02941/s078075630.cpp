#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> xs(n), ys(n);
    for (int& x : xs) {
        cin >> x;
    }
    for (int& y : ys) {
        cin >> y;
    }
    set<pair<int, int>> missing;
    for (int i = 0; i < n; ++i) {
        if (xs[i] < ys[i]) {
            missing.insert(make_pair(ys[i], i));
        }
    }
    long long count = 0;
    while (!missing.empty()) {
        auto p = *missing.rbegin();
        missing.erase(p);
        int i = p.second;
        int diff = ys[i]-xs[i];
        int sides = ys[(i+n-1)%n] + ys[(i+1)%n];
        int steps = diff / sides;
        if (steps == 0) {
            cout << -1 << endl;
            return 0;
        }
        count += steps;
        ys[i] -= sides * steps;
        if (ys[i] > xs[i]) {
            missing.insert(make_pair(ys[i], i));
        }
    }
    cout << count << endl;
    return 0;
}

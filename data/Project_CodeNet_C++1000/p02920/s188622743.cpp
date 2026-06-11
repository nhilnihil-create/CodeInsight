#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> xs(1 << n);
    for (int& x : xs) {
        cin >> x;
    }
    multiset<int, function<bool(int, int)>> potential_slimes(xs.begin(), xs.end(), [](int a, int b) { return a > b; });
    vector<int> realized_slimes = {*potential_slimes.begin()};
    potential_slimes.erase(potential_slimes.begin());
    for (int t = 0; t < n; ++t) {
        for (int i = 0; i < (1 << t); ++i) {
            auto it = potential_slimes.upper_bound(realized_slimes[i]);
            if (it == potential_slimes.end()) {
                cout << "No" << endl;
                return 0;
            }
            realized_slimes.push_back(*it);
            potential_slimes.erase(it);
        }
    }
    cout << "Yes" << endl;
    return 0;
}

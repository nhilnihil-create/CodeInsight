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
    sort(xs.begin(), xs.end(), [](int a, int b) { return a > b; });
    vector<int> chosen(1 << n, -1);
    chosen[0] = 0;
    for (int t = 1; t <= n; ++t) {
        int i = 0, j = 0;
        for (int k = 0; k < (1 << (t-1)); ++k) {
            while (j < (1 << n) && (chosen[j] != -1 || xs[j] == xs[i])) ++j;
            if (j == (1 << n)) {
                cout << "No" << endl;
                return 0;
            }
            chosen[j] = t;
            ++i;
            while (i < (1 << n) && (chosen[i] == -1 || chosen[i] == t)) ++i;
            j = max(i, j);
        }
    }
    cout << "Yes" << endl;
    return 0;
}

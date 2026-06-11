#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    bool is_zero = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) is_zero = true;
    }
    if (is_zero) {
        cout << 0 << '\n';
        return 0;
    }
    long long answer = 1;
    double g = 1;
    for (int i = 0; i < n; ++i) {
        g *= a[i];
        if (g > 2e18) {
            answer = -1;
            break;
        }
        answer *= a[i];
    }
    cout << (answer <= (long long) (1e18) ? answer : -1) << '\n';
    return 0;
}
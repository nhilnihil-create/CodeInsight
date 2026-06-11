#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> A;
    vector<bool> exist(n + 5, false);
    for (int i = 0; i < n; i++) {
        int a;cin >> a;
        A.push_back(a);
    }
    vector<int> minus(n), plus(n);
    for (int i = 0; i < n; i++) {
        minus[i] = i - A[i];
        plus[i] = i + A[i];
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());
    ll ans = 0;
    for (auto x: plus) {
        auto top = upper_bound(minus.begin(), minus.end(), x);
        auto bottom = lower_bound(minus.begin(), minus.end(), x);
        ans += top - bottom;
    }
    cout << ans << endl;
    return 0;
}
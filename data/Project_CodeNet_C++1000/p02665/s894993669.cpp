#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> a[i];
    vector<long long> lb(n + 1), ub(n + 1);
    lb[n] = ub[n] = a[n];
    for (int i = n; i >= 1; --i) {
        lb[i - 1] = ((lb[i] + 1) >> 1) + a[i - 1];
        ub[i - 1] = ub[i] + a[i - 1];
    }
    if (n == 0 && a[0] != 1) { cout << "-1\n"; return 0; }
    if (n == 0 && a[0] == 1) { cout << "1\n"; return 0; } 
    if (1 < lb[0] || ub[0] < 1) {
        cout << "-1\n";
        return 0;
    }
    long long tot = 1, ans = tot;
    for (int i = 1; i <= n; ++i) {
        ans += tot = min((long long) ub[i], (tot - a[i - 1]) * 2);
    }
    cout << ans << '\n';
    return 0; 
}
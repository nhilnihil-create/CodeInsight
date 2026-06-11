#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        vector<int> q{p[i - 1], p[i], p[i + 1]};
        sort(q.begin(), q.end());
        if (q[1] == p[i]) ans++;
    }
    cout << ans;
    return 0;
}

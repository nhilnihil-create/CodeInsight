#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(b, a);
    }
    sort(v.begin(), v.end());
    set<int> s;
    for (int i = 1; i <= m; ++i)
        s.insert(i);
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        auto it = s.lower_bound(v[i].second);
        if (it == s.end()) continue;
        ans += v[i].first;
        s.erase(it);
    }
    cout << ans << endl;
    return 0;
}
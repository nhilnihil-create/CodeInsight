#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
    #include "_/debug.h"
#else 
    #define out(...) 69;
#endif

int main() { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto u = make_pair(a[i].first - a[j].first, a[i].second - a[j].second);
            ++cnt[u];
        }
    }
    int mx = 0;
    for (auto x : cnt) {
        mx = max(mx, x.second);
    }
    cout << n - mx << '\n';
}
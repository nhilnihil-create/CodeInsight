#include <bits/stdc++.h>

//#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int,int>> v;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        v.push_back({t,i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) cout << v[i].second << ' ';
    cout << '\n';
}
/*

 */
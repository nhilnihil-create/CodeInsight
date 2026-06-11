#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int e, i = 0; i < n; i++) {
        cin >> e;
        a.emplace_back(e, i);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    set<int> index;
    long long ans = 0;
    for (const auto& e : a) {
        int v, i; tie(v, i) = e;
        vector<int> l(2, -1), r(2, n);
        const auto itr = index.lower_bound(i);
        auto it = itr;
        for (int j = 0; j < 2; j++) {
            if (it != index.end()) r[j] = *(it++);
        }
        it = itr;
        for (int j = 0; j < 2; j++) {
            if (it != index.begin()) l[j] = *(--it);
        }
        long long v1 = (i - l[0]) * (r[1] - r[0]);
        long long v2 = (r[0] - i) * (l[0] - l[1]);
        ans += (v1 + v2) * v;
        index.insert(i);
    }
    
    cout << ans << endl;
    return 0;
}
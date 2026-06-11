#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

bool solve() {
    int N; cin >> N;
    multiset<int> ms;
    ms.insert(-1);
    rep(i, 0, 1 << N) {
        int s; cin >> s;
        ms.insert(s);
    }
    vector<int> used;
    auto mx = ms.rbegin();
    used.push_back(*mx);
    ms.erase(*mx);
    rep(loop, 0, N) {
        vector<int> add;
        sort(used.begin(), used.end());
        rep(i, 0, used.size()) {
            auto e = ms.lower_bound(used[i]);
            --e;
            if(*e == -1) return false;
            add.push_back(*e);
            ms.erase(e);
        }
        rep(i, 0, add.size()) used.push_back(add[i]);
    }
    return true;
}

int main() {
    cout << (solve() ? "Yes" : "No") << '\n';
    return 0;
}

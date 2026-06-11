#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

bool solve() {
    int N; cin >> N;
    multiset<int> ms;
    rep(i, 0, 1 << N) {
        int s; cin >> s;
        ms.insert(s);
    }
    auto mx = ms.end();
    --mx;
    vector<int> used;
    used.push_back(*mx);
    ms.erase(mx);
    rep(loop, 0, N) {
        vector<int> add;
        sort(used.begin(), used.end(), greater<int>());
        for(auto u : used) {
            auto e = ms.lower_bound(u);
            if(e == ms.begin()) return false;
            --e;
            add.push_back(*e);
            ms.erase(e);
        }
        for(auto a : add) used.push_back(a);
    }
    return true;
}

int main() {
    cout << (solve() ? "Yes" : "No") << '\n';
    return 0;
}

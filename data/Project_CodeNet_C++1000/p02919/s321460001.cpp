#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; ++i) {
        int a; cin >> a;
        P[i] = make_pair(a, i);
    }
    sort(P.begin(), P.end(), greater<pair<int, int>>());
    multiset<int> ms;
    ms.insert(-1);
    ms.insert(-1);
    ms.insert(N);
    ms.insert(N);
    int64_t ans = 0;
    for(auto &e : P) {
        int a, i; tie(a, i) = e;
        auto c = ms.lower_bound(i);
        auto v = next(c);
        auto x = prev(c);
        auto z = prev(x);
        ans += (int64_t)(i - *x) * (*v - *c) * a;
        ans += (int64_t)(*x - *z) * (*c - i) * a;
        ms.insert(i);
    }
    cout << ans << '\n';
    return 0;
}

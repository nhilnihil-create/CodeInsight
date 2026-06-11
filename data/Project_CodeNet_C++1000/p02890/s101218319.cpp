#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename T, typename Can> T bsearch(T L, T R, Can&& can, bool left_feasible = true) {
    static_assert(is_convertible<decltype(can), function<bool(T)>>::value, "can must be bool(T)");
    T& feasible = left_feasible ? L : R;
    T& infeasible = left_feasible ? R : L;
    while(R - L > 1) {
        T M = L + (R - L) / 2;
        (can(M) ? feasible : infeasible) = M;
    }
    return feasible;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> counter;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        counter[a]++;
    }
    priority_queue<int> pq;
    int total = 0;
    for(auto& p : counter) {
        pq.push(p.second);
        total += p.second;
    }
    vector<int> ans(n + 1);
    for(int ops = n, k = 0; ops >= 0; ops--) {
        while(pq.top() > ops) {
            total--;
            pq.push(pq.top() - 1);
            pq.pop();
        }
        int max_k = bsearch<int>(0, n + 1, [&](int k) {
            return total >= (ll) ops * k;
        });
        while(k <= max_k) {
            ans[k++] = ops;
        }
    }
    for(int k = 1; k <= n; k++) {
        cout << ans[k] << endl;
    }
    return 0;
}

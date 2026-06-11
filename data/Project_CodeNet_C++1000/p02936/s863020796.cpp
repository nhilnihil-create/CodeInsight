#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using boost::irange;
using boost::sort;
using boost::adaptors::reversed;
template<typename T>
using vec2 = vector<vector<T>>;

void solve(int v, int c, const vec2<int>& w, const vector<int>& x, vector<int>& cnt, vector<bool>& visited) {
    visited[v] = true;
    c += x[v];
    cnt[v] = c;
    for (auto vi : w[v]) {
        if (visited[vi]) continue;
        solve(vi, c, w, x, cnt, visited);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vec2<int> w(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int ai, bi;
        cin >> ai >> bi;
        w[ai].push_back(bi);
        w[bi].push_back(ai);
    }
    vector<int> x(n + 1, 0);
    for (int i = 1; i <= q; i++) {
        int pq, xq;
        cin >> pq >> xq;
        x[pq] += xq;
    }
    vector<int> cnt(n + 1, 0);
    vector<bool> visited(n + 1, false);
    solve(1, 0, w, x, cnt, visited);
    for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    cout << endl;
}

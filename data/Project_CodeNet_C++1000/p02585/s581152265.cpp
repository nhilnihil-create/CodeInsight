
// Problem: D - Moving Piece
// Contest: AtCoder - AtCoder Beginner Contest 175
// URL: https://atcoder.jp/contests/abc175/tasks/abc175_d
// Parsed on: 2020-09-02 13:00:10
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;
using ll = long long;

vector<ll> simulate(vector<ll> const &p, vector<ll> const &c, int n) {
    vector<ll> ans;
    int iter = p[n];
    ll lastAns = c[iter];
    ans.push_back(lastAns);
    while (iter != n) {
        iter = p[iter];
        lastAns += c[iter];
        ans.push_back(lastAns);
    }
    return ans;
}

int main() {
    ll ans = numeric_limits<ll>::min();
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    for (auto &e : p) {
        int tmp;
        cin >> tmp;
        tmp--;
        e = tmp;
    }
    for (auto &e : c) cin >> e;

    for (int a = 0; a < n; a++) {
        auto sr = simulate(p, c, a);

        int tmpK = k;
        if (sr.back() <= 0) {
            if (tmpK > sr.size()) tmpK = sr.size();
            ans = max(ans, *max_element(sr.begin(), sr.begin() + tmpK));
        } else if (sr.size() >= k) {
            ans = max(ans, *max_element(sr.begin(), sr.begin() + k));
        } else {
            auto secondLastCycleSequence = ((k / sr.size()) - 1);
            ll base = secondLastCycleSequence * sr.back();

            ans = max(ans, base + *max_element(sr.begin(), sr.end()));
            if (k % sr.size())
                ans = max(ans, base + sr.back() +
                                   *max_element(sr.begin(),
                                                sr.begin() + (k % sr.size())));
        }
    }

    cout << ans;
    return 0;
}

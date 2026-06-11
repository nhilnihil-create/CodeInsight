#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<P> prime_fact(int n) {
    if (n == 1) return vector<P>(1, {1, 0});
    vector<P> res;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        res.emplace_back(i, 0);
        while (n % i == 0) {
            res.rbegin()->second++;
            n /= i;
        }
    }
    if (n > 1) res.emplace_back(n, 1);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<P> pf = prime_fact(n);
    cout << n << ":";
    for (auto &p : pf) {
        REP(i, p.second) {
            cout << " " << p.first;
        }
    }
    cout << endl;

    return 0;
}

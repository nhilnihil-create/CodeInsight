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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> X(N), L(N);
    vector<pair<ll, ll>> right_left(N);
    REP(i, N) {
        cin >> X[i] >> L[i];
        right_left[i] = {X[i] + L[i], X[i] - L[i]};
    }
    SORT(right_left);
    int i = 0;
    ll limit = -1e9;
    int res = 0;
    while (i < N) {
        while (i < N && right_left[i].second < limit) ++i;
        if (i == N) break;
        limit = right_left[i].first;
        ++res;
        ++i;
    }
    cout << res << endl;

    return 0;
}

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
    vector<queue<int>> A(N);
    REP(i, N) {
        REP(j, N - 1) {
            int a;
            cin >> a;
            A[i].emplace(--a);
        }
    }
    int res = -1;
    vector<int> cnt(N);
    while (true) {
        bool end = true;
        bool impossible = true;
        REP(i, N) {
            if (A[i].empty()) continue;
            end = false;
            int j = A[i].front();
            if (A[j].front() == i) {
                A[i].pop();
                A[j].pop();
                cnt[i] = cnt[j] = max(cnt[i], cnt[j]) + 1;
                impossible = false;
            }
        }
        if (end) {
            REP(i, N) res = max(res, cnt[i]);
            break;
        }
        if (impossible) break;
    }
    cout << res << endl;

    return 0;
}
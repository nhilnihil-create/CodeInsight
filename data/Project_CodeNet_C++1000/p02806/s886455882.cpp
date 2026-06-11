// https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<string, int>> v(N);
    REP(i, N) { cin >> v[i].first >> v[i].second; }
    string w;
    cin >> w;
    int sum = 0;
    for (int i = N - 1; i > 0; i--) {
        if (v[i].first == w) {
            break;
        }
        sum += v[i].second;
    }
    cout << sum << endl;

    return 0;
}

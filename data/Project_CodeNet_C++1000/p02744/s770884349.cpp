#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(v) for (auto itr = v.begin(), itr != v.end(); ++itr)
#define LB(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define UB(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;
void dfs(const string &S = "", char C = 'a') {
    if (SZ(S) == N) {
        cout << S << endl;
        return;
    }
    for (char c = 'a'; c <= C; ++c) {
        if (c == C)
            dfs(S + c, C + 1);
        else
            dfs(S + c, C);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    dfs();

    return 0;
}

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

bool dfs(int a0, int a1, int l, int m, const set<int> &st) {
    if (st.empty()) { return m == (l ^ a0) && a0 == (m ^ a1); }
    set<int> copy = st;
    for (auto &r : st) {
        if (m == (l ^ r)) {
            copy.erase(r);
            if (dfs(a0, a1, m, r, copy)) return true;
            copy.insert(r);
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> a(N);
    map<int, int> mp;
    REP(i, N) {
        cin >> a[i];
        mp[a[i]]++;
    }
    bool yes = false;
    if (SZ(mp) == 1 && a[0] == 0) {
        yes = true;
    } else if (SZ(mp) == 2 && N % 3 == 0 && mp[0] == N / 3) {
        yes = true;
    } else if (SZ(mp) == 3 && N % 3 == 0) {
        bool tmp = true;
        int sum = 0;
        for (auto &p : mp) {
            tmp = tmp && (p.second == N / 3);
            sum ^= p.first;
        }
        yes = tmp && (sum == 0);
    }
    if (yes)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

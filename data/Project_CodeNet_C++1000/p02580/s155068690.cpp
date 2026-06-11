#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define single_test

const int maxn = 3e5 + 3;

set<pair<int,int>> st;
int freq[maxn];

inline void add(int x) {
    st.erase({freq[x], x});
    freq[x]++;
    st.insert({freq[x], x});
}

inline void remove(int x) {
    st.erase({freq[x], x});
    freq[x]--;
    st.insert({freq[x], x});
}

int ask(vector<array<int,2>> v) {
    sort(v.begin(), v.end());
    st.clear();
    memset(freq, 0, sizeof freq);
    const int N = v.size();
    for (auto &it: v) {
        freq[it[1]]++;
    }

    for (int i = 1; i < maxn; ++i) {
        if (freq[i]) {
            st.insert({freq[i], i});
        }
    }
    int ret = 0;
    for (int i = 0; i < N; ) {
        int cur = v[i][0], cnt = 0;
        int index = i;
        while (i < N && v[i][0] == cur) {
            remove(v[i][1]);
            ++i;
            ++cnt;
        }
        int ans = cnt;
        if (!st.empty()) {
            auto it = --st.end();
            ans += it->first;
        }
        ret = max(ret, ans);
        i = index;
        while (i < N && v[i][0] == cur) {
            add(v[i][1]);
            ++i;
        }
    }
    return ret;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 2>> v(q);
    for (int i = 0; i < q; ++i) {
        cin >> v[i][0] >> v[i][1];
    }
    int ans = ask(v);
    for (auto &it: v) {
        swap(it[0], it[1]);
    }
    ans = max(ans, ask(v));
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
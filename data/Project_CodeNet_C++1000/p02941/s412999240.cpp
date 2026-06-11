#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e8;
const int INF = 1e9;
const int MOD = 998244353;


void bad() {
    cout << -1;
    exit(0);
}

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] != b[i])
            st.emplace(b[i], i);
    }
    ll ans = 0;
    while (!st.empty()) {
        int ind = st.rbegin()->second;
        st.erase(--st.end());
        int pre = (ind - 1 + n) % n;
        int next = (ind + 1) % n;
        ll sm = b[pre] + b[next];
        if (b[ind] - a[ind] < sm)
            bad();
        ll k = (b[ind] - a[ind]) / sm;
        ans += k;
        b[ind] -= k * sm;
        if (b[ind] != a[ind])
            st.emplace(b[ind], ind);
    }
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            bad();
    cout << ans;
}
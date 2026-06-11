#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> ans;
    string s;
    cin >> s;
    vector<int> a;
    for (int i = 0; i < n; i++) if (s[i] == 'o') a.pb(i);
    n = a.size();
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        int ind = upper_bound(all(a), a[i] + c) - a.begin();
        dp[i] = 1 + (ind < n ? dp[ind] : 0);
    }
    if (n > 1 && dp[1] < k) ans.pb(a[0]);
    if (n == 1) ans.pb(a[0]);
    int cur = 1, last = a[0];
    for (int i = 1; i < n; i++) {
        int ind = upper_bound(all(a), last + c) - a.begin();
        ind = max(ind, i + 1);
        if (cur + (ind < n ? dp[ind] : 0) < k) ans.pb(a[i]);
        if (a[i] > last + c) {
            cur++;
            last = a[i];
        }
    }
    for (auto &c : ans) cout << c + 1 << "\n";
    return 0;
}

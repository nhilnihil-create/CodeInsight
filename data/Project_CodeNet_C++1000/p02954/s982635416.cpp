#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define quick                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define time cerr << (0.1 * clock()) / CLOCKS_PER_SEC << endl;
#define mod 1000000007
typedef long long ll;
typedef pair<ll, ll> pl;
#define forn(n) for (ll i = 0; i < ll(n); i++)

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> vr(n), vl(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            vr[i] = i;
        } else {
            vr[i] = vr[i - 1];
        }
    }
    vl[n - 1] = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'L') {
            vl[i] = i;
        } else {
            vl[i] = vl[i + 1];
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            int dis = (vl[i] - i - 1) % 2;
            ans[vl[i] + dis - 1]++;
        } else {
            int dis = (i - vr[i] - 1) % 2;
            ans[vr[i] + 1 - dis]++;
        }
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << '\n';
}

int main() {
    quick;
    solve();
    // ll t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
}
// 6/30 解き直し
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    map<string, ll> mp;
    rep(i, n) {
        sort(s[i].begin(), s[i].end());
        mp[s[i]]++;
    }

    ll res = 0;
    for (auto p : mp) {
        res += (p.second * (p.second - 1) / 2);
    }

    cout << res << endl;
}
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<ll>> C(26, vector<ll>());

    ll n  = s.size();
    for (ll i = 0; i < n; ++i) {
        char c = s[i] - 'a';
        C[c].emplace_back(i);
    }

    vector<ll> idx(26, 0);

    ll m = t.size();
    ll res = 0;
    ll cur = 0;
    char prev = '_';
    for (ll i = 0; i < m; ++i) {
        char c = t[i];
        ll j = c - 'a';
        if (c == prev) {
            ++cur;
        }

        auto iter = lower_bound(C[j].begin(), C[j].end(), cur);
        if (iter == C[j].end()) {
            if (iter == C[j].begin()) {
                res = -1;
                break;
            }
            ++res;
            cur = 0;
            iter = lower_bound(C[j].begin(), C[j].end(), cur);
        }
        cur = *iter;
        prev = c;

    }

    if (res == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << n * res + cur + 1 << endl;
}

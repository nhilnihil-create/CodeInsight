#include <bits/stdc++.h>

#define ll long long int

using namespace std;


vector<ll> Zalgo(const string & s) {
    ll n = s.size();
    vector<ll> res(n);
    res[0] = n;
    ll i = 1, j = 0;
    while (i < n) {
        while (i+j < n && s[j] == s[i+j]) ++j;
        res[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        ll k = 1;
        while (i + k < n && k + res[k] < j) {
            res [i+k] = res[k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        string t = s.substr(i);

        auto lcp = Zalgo(t);

        for (ll j = 0; j < t.size(); ++j) {
            ll l = min(lcp[j], j);
            res = max(res, l);
        }
    }

    cout << res << endl;
}

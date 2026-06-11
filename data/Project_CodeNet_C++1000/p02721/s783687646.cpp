#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 

vector<ll> sub(const string &s, ll c) {
    ll n = s.size();
    ll cur = 0, last = -c-1;
    vector<ll> res(n+1, 0);
    for (ll i = 0; i < n; ++i) {
        if (i - last > c && s[i] == 'o') {
            ++cur, last = i;
        }
        res[i+1] = cur;
    }
    return res;
}

int main() {
    ll n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    const auto & left = sub(s, c);
    string t = s;
    reverse(t.begin(), t.end());
    const auto & right  = sub(t, c);

    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'x') continue;
        if (left[i] + right[n-i-1] < k) cout << i+1 << endl;
    }
}

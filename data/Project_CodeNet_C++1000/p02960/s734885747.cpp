#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    string s; cin >> s;
    reverse(all(s));
    vvll dp(s.size(), vll(13));
    // process first line
    if (s[0] == '?') {
        rep(i, 10) {
            dp[0][i] = 1;
        }
    } else {
        ll num = s[0] - '0';
        dp[0][num] = 1;
    }
    //for (auto elem : dp[0]) cout << elem << " "; cout << endl;

    if (s.size() == 1) {
        cout << dp[s.size()-1][5] << endl;
        return 0;
    }

    for (ll i = 1; i < s.size(); i++) {
        set<ll> _candidate;
        if (s[i] == '?') {
            rep(j, 10) _candidate.insert(j * modpow(10, i, 13) % 13);
        } else {
            _candidate.insert((s[i] - '0') * modpow(10, i, 13) % 13);
        }
        vll candidate;
        for (auto elem : _candidate) {
            candidate.push_back(elem);
        }
        rep(j, 13) {
            rep(k, candidate.size()) {
                //cout << "i: " << i << ", j: " << j << ", k: " << k << endl;
                dp[i][(j + candidate[k]) % 13] = (dp[i][(j + candidate[k]) % 13] + dp[i-1][j]) % (ll)(1e9+7);
            }
        }
    }
    //for (auto elem1 : dp) {
    //    for (auto elem : elem1) cout << elem << " "; cout << endl;
    //}
    cout << dp[s.size()-1][5] << endl;
    return 0;
}
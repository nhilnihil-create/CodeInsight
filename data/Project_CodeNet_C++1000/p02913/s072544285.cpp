#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

vector<int> z_algorithm(const string &s) {
    int n = s.size();
    vector<int> prefix(n);
    for(int i = 1, j = 0; i < n; i++) {
        if ((i + prefix[i - j]) < (j + prefix[j])) {
            prefix[i] = prefix[i - j];
        }
        else {
            int k = max(0, j + prefix[j] - i);
            while(((i + k) < n) && (s[k] == s[i + k])) k++;
            prefix[i] = k;
            j = i;
        }
    }
    prefix[0] = n;
    return prefix;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    rep(i, n) {
        string ss = s.substr(i);
        auto za = z_algorithm(ss);
        reps(j, 1, n - i) {
            ans = max(ans, min(j, (ll)za[j]));
        }
    }
    cout << ans << endl;
    return 0;
}

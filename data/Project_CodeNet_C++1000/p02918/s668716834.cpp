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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll bad = 0;
    rep(i, n) {
        if (s[i] == 'L') {
            if ((i == 0) || (s[i - 1] == 'R')) {
                bad++;
            }
        }
        else {
            if ((i == (n - 1)) || (s[i + 1] == 'L')) {
                bad++;
            }
        }
    }
    bad = max(1LL, bad - k * 2);
    cout << (n - bad) << endl;
    return 0;
}

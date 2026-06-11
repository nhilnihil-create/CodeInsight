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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    set<ll> ins;
    rreps(i, 1, n + 1) {
        ll tmp = 0;
        ll cv = 2 * i;
        while(cv <= n) {
            if (ins.count(cv) > 0) tmp++;
            cv += i;
        }
        if ((tmp % 2) != a[i - 1]) {
            ins.insert(i);
        }
    }
    printf("%lld\n", sz(ins));
    for(auto x : ins) printf("%lld\n", x);
    return 0;
}

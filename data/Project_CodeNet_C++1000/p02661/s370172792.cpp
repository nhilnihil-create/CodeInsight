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
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    if (n % 2 == 1) {
        ll l = a[n / 2];
        ll r = b[n / 2];
        cout << (r - l + 1) << endl;
    }
    else {
        ll l = a[n / 2 - 1] + a[n / 2];
        ll r = b[n / 2 - 1] + b[n / 2];
        cout << (r - l + 1) << endl;
    }
    return 0;
}

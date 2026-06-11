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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    priority_queue<ll> pq;
    rep(i, n) pq.push(a[i]);
    rep(i, m) {
        ll v = pq.top(); pq.pop();
        v /= 2;
        pq.push(v);
    }
    ll ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}

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
    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(all(ab), [](pair<ll, ll> &a, pair<ll, ll> &b){ return a.first < b.first; });
    auto it = ab.begin();
    priority_queue<ll> pq;
    ll ans = 0;
    rrep(i, m) {
        while((it != ab.end()) && (i <= (m - it->first))) {
            pq.push(it->second);
            it++;
        }
        if (pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    // rep(i, n) printf("%lld:%lld\n", ab[i].first, ab[i].second);
    return 0;
}

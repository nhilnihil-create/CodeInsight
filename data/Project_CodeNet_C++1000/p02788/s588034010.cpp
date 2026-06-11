//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    ll d, a;
    cin >> n >> d  >> a;
    vector<P> x(n);
    rep(i, n) {
        cin >> x[i].first >> x[i].second;
    }
    sort(all(x));
    ll ans = 0;
    map<int, ll> mp;
    rep(i, n) {
        mp[x[i].first];
    }
    ll damage = 0;
    for(auto nn:mp) {
        damage += nn.second;
        P now = *(upper_bound(all(x), P(nn.first, LINF))-1);
        int dam = (now.second - damage + a - 1)/a;
        if(dam < 0) dam = 0;
        ans += dam;
        damage += dam*a;
        auto itr = upper_bound(all(x), P(now.first+2*d, LINF));
        if(itr != x.end()) {
            mp[(*itr).first] -= dam*a;
        }
    }

    cout << ans << endl;
}
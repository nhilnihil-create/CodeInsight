#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define MOD 1000000007LL

#define rep(i, n) for(ll (i) = 0LL;(i) < (ll)(n);(i)++)
#define rep2(i, s, e) for(ll (i) = (ll)(s);(i) < (ll)(e);(i)++)
#define repi(i, n) for(ll (i) = 0LL;(i) <= (ll)(n);(i)++)
#define repi2(i, s, e) for(ll (i) = (ll)(s);(i) <= (ll)(e);(i)++)
#define per(i, n) for(ll (i) = (ll)(n) - 1LL;(i) >= 0LL;(i)--)
#define per2(i, s, e) for(ll (i) = (ll)(s) - 1LL;(i) >= (ll)(e);(i)--)
#define peri(i, n) for(ll (i) = (ll)(n);(i) >= 0LL;(i)--)
#define peri2(i, s, e) for(ll (i) = (ll)(s);(i) >= (ll)(e);(i)--)
#define iter(i, it) for(auto &(i): (it))

template<typename T, typename U> ostream& operator<<(ostream &s, const pair<T, U> m) {
    cout << "(" << m.first << ", " << m.second << ")";
    return s;
}
template<typename T, typename U> ostream& operator<<(ostream &s, const map<T, U> m) {
    ll c = 0;
    cout << "{ ";
    iter(i, m) cout << i << (c++ == m.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
    cout << "{ ";
    rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}
template<typename T> ostream& operator<<(ostream &s, const list<T> &v) {
    ll c = 0;
    cout << "{ ";
    iter(i, v) cout << i << (c++ == v.size() - 1 ? " " : ", ");
    cout << "}";
    return s;
}

int main(void) {
    ll H, W, M;
    cin >> H >> W >> M;
    vector<vector<ll>> rows(H), cols(W);
    set<pair<ll, ll>> bomb;
    ll hmax = 0, wmax = 0;
    vector<ll> hh, ww;
    rep(i, M) {
        ll h, w;
        cin >> h >> w;
        h--; w--;
        rows[h].push_back(w);
        cols[w].push_back(h);
        bomb.emplace(h, w);
    }
    rep(i, H) hmax = max(hmax, (ll)rows[i].size());
    rep(i, W) wmax = max(wmax, (ll)cols[i].size());
    rep(i, H) {
        if(hmax == rows[i].size()) hh.push_back(i);
    }
    rep(i, W) {
        if(wmax == cols[i].size()) ww.push_back(i);
    }
    ll ans = hmax + wmax - 1;
    iter(h, hh) {
        iter(w, ww) {
            if(bomb.find({h, w}) == bomb.end()) {
                cout << ans + 1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

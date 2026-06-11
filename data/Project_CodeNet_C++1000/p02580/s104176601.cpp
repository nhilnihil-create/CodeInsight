#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
 
int main() {
    ll h, w, m, a, b;
    cin >> h >> w >> m;
    vector<ll> l(h, 0), r(w, 0);
    map<P, ll> t;
    rep1(i, m){
        cin >> a >> b;
        a--;
        b--;
        l[a]++;
        r[b]++;
        P p = make_pair(a, b);
        t[p]++;
    }
    ll max_l = *max_element(l.begin(), l.end());
    ll max_r = *max_element(r.begin(), r.end());
    vector<ll> ndx_l, ndx_r;
    rep1(i, h) if (l[i] == max_l) ndx_l.push_back(i);
    rep1(i, w) if (r[i] == max_r) ndx_r.push_back(i);
    ll ans = max_l + max_r - 1;
    for (auto x: ndx_l){
        for (auto y: ndx_r){
            P p = make_pair(x, y);
            if (t[p]==0){
                ans = max_l + max_r;
                cout << ans << endl;
                return 0;
            }
        }
    } 
    cout << ans << endl;
}
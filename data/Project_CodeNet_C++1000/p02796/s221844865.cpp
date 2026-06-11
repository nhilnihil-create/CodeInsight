#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    ll n; cin >> n;
    vector<pair<ll, ll>> v;
    rep(i, n) {
        ll x, l; cin >> x >> l;
        v.push_back(make_pair(x + l, x)); // 位置 + 腕が短い順に貪欲
    }
    sort(all(v));
    ll ans = 1; // 残すロボットのカウント。一番最初は絶対採用
    ll now = v[0].first; // 現在の腕を含めた右端
    Rep(i, 1, n) {
        if(now <= v[i].second - (v[i].first - v[i].second)) { // first - secondが腕
            ans++;
            now = v[i].first;
        }
    }
    cout << ans << endl;
}

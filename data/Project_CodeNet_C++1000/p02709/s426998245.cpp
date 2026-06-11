//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    multimap<ll, int> mp;
    rep(i, n) mp.emplace(a[i], i);

    vvi dp(1, vi(1));
    int i = 0;
    ll ans = 0;
    for(auto itr = mp.end(); itr != mp.begin();) {
        itr--;
        dp.emplace_back(vi(i+2, 0));
        rep(j, i+2) {
            if(j) chmax(dp[i+1][j], dp[i][j-1] + itr->first*abs(itr->second-j+1));
            if(j != i+1) chmax(dp[i+1][j], dp[i][j] + itr->first*abs(itr->second-(n-1-(i-j))));
            chmax(ans, dp[i+1][j]);
        }
        i++;
    }
    cout << ans << endl;
}
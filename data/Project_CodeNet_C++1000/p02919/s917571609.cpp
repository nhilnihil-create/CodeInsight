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
using vi = vector<int>;
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
    vi p(n), inp(n+1);
    rep(i, n) {
        cin >> p[i];
        inp[p[i]] = i+1;
    }
    set<int> se;
    se.insert(0);
    se.insert(n+1);
    se.insert(inp[n]);
    ll ans = 0;
    for(int i = n-1; i > 0; i--) {
        auto itr = se.lower_bound(inp[i]);
        if(*itr != n+1) {
            ans += ll(*next(itr)-*itr)*(inp[i]-*prev(itr))*i;
        }
        itr = prev(itr);
        if(*itr != 0) {
            ans += ll(*next(itr)-inp[i])*(*itr-*prev(itr))*i;
        }
        se.insert(inp[i]);
    }
    cout << ans << endl;
    
}
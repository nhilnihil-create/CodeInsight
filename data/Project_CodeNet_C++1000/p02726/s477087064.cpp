/**
*	created: 11.08.2020 23:12:01
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, x, y; cin >> n >> x >> y;
    x--; y--;
    vector<int> v(n);
    rep(i,n) {
        vector<int> dist(n,INF);
        queue<int> q;
        auto pushin = [&] (int v, int d) {
            if (dist[v] != INF) return;
            dist[v] = d;
            q.push(v);
        };
        pushin(i,0);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int d = dist[v];
            if (v - 1 >= 0) pushin(v-1,d+1);
            if (v + 1 < n) pushin(v+1,d+1);
            if (v == x) pushin(y,d+1);
            if (v == y) pushin(x,d+1);
        }
        rep(j,n) v[dist[j]]++;
    }
    rep2(i,1,n) cout << v[i] / 2 << endl;
    return 0;
}
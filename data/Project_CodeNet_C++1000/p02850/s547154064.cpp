/**
*	created: 21.09.2020 15:46:01
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
#define len(x) ll(x.size())
using ll = long long;
using P = pair<int,int>;
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T b) {if (b < a) {a = b; return 1;} return 0;}
inline void print(P a) {cout << a.first << " " << a.second << endl;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

struct edge {
    int to, id;
    edge(int to_, int id_) : to(to_), id(id_) {}
};

vector<edge> eg[100100];
int ans[100100];

void dfs(int v, int c, int p) {
    int k = 1;
    for (auto e : eg[v]) {
        int u = e.to;
        int i = e.id;
        if (u == p) continue;
        if (k == c) k++;
        ans[i] = k;
        k++;
        dfs(u,ans[i],v);
    }
}

signed main() {
    int n; cin >> n;
    rep(i,n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        edge e1(b,i), e2(a,i);
        eg[a].push_back(e1);
        eg[b].push_back(e2);
    }
    dfs(0,-1,-1);
    int num = 0;
    rep(i,n-1) chmax(num,len(eg[i]));
    cout << num << endl;
    rep(i,n-1) cout << ans[i] << endl;
    return 0;
}
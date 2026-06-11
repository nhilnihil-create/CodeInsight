#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
 
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define all(c) (c).begin(), (c).end()
#define sz(x) ((int)(x).size())
 
 
template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}
 
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
 
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for(int i = 0; i < v.size(); i++) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}
 
#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
 
const ll MOD = 1e9 + 7; //998244353
constexpr ll INF = 1e18;
const int MX = 3010;

V <int> g[100001];
int h[100001];
bool good[100001], vis[100001];
int n, m, u, v;


int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m ;
    for(int i =1; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    function < void (int) > dfs = [&] (int u){
        vis[u] = 1;
        for(auto v : g[u]){
            if(h[u] <= h[v])
                good[u] = 1;

            if(!vis[v])
                dfs(v);
        }
        return ;
    };
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i);
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += (good[i] ? 0 : 1);

    cout << ans << endl;


    return 0;
}
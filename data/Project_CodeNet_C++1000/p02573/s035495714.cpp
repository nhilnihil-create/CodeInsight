//In the name of Allah :)
#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return string(1,c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
template<class A> string to_string(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string to_string(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < (int)v.size(); i++) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> string to_string(bitset<SZ> b) {
	string res = ""; for(size_t i = 0; i < SZ; i++) res += char('0'+b[i]);
	return res; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) { // containers with begin(), end()
	bool fst = 1; string res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += to_string(x);
	}
	res += "}"; return res;
}
template<class A, class B> string to_string(pair<A,B> p) {
	return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define wis(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
#else
#define wis(...) 0
#endif
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9 + 7, INF = 1e9 + 5;
const ll LONG_INF = 1e18 + 10;
inline ll powmod(ll a, ll b){ll res=1;for(;b;b>>=1,a=a*a%MOD)if(b&1)res=res*a%MOD;return res;}
inline ll power(ll a, ll b){ll res=1;for(;b;b>>=1,a=a*a)if(b&1)res=res*a;return res;}

const int MAXN = 2e5 + 10;
vector <int> adj[MAXN];
bitset <MAXN> mark;

int dfs(int v){
    if(mark[v]){
        return 0;
    }
    mark[v] = 1;
    int ans = 1;
    for(int i : adj[v]){
        ans += dfs(i);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dfs(i));
    }
    cout << ans << '\n';
}

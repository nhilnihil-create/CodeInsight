#include <bits/stdc++.h>

#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vi >
#define vpii vector<pii >
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define mod(x) ((x)%MOD)
#define o(X) (1<<(X))
#define oL(X) (1LL<<(X))
#define LL long long
#define ppt(x) __builtin_popcount(x)
using namespace std;
const int INF=0x3f3f3f3f,N=1e6+5,MOD=998244353;
const LL INF_LL=0x3f3f3f3f3f3f3f3fLL;

template<typename T>
inline int getplc(T x,int y) { return (x>>y)&1; }
template<typename T>
T square(T x) {return x*x;}

LL qpow(LL a,LL b=MOD-2,LL _MOD=MOD){
	LL res=1;
	for(;b;b>>=1,a=a*a%_MOD){
		if(b&1)res=res*a%_MOD;
	}
	return res;
}

template <typename T>
T Smax(T x) { return x; }
template<typename T, typename... Args>
T Smax(T a, Args... args) {
	return max(a, Smax(args...));
}
template <typename T>
T Smin(T x) { return x; }
template<typename T, typename... Args>
T Smin(T a, Args... args) {
	return min(a, Smin(args...));
}

template <typename T>
#define errorl(args...) {  \
	string _s = #args;   \
	replace(_s.begin(), _s.end(), ',', ' ');  \
    stringstream _ss(_s);  \
    istream_iterator<string> _it(_ss);  \
    errl(_it, args);  \
}
void errl(istream_iterator<string> it) {}
template<typename T, typename... Args>
void errl(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	errl(++it, args...);
}
#define error(args...) {  \
  string _s = #args;  \
  replace(_s.begin(), _s.end(), ',', ' ');  \
  stringstream _ss(_s);  \
  istream_iterator<string> _it(_ss);  \
  err(_it, args);  \
  cerr<<endl; \
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << "=" << a << " # ";
	err(++it, args...);
}

vi g[N];
int vis[N];

void dfs(int x) {
  vis[x] = 1;
  for (auto v : g[x]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

void Solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v), g[v].pb(u);
  }

  int ans = -1;
  rep (i, 1, n) if (!vis[i]) dfs(i), ans++;

  cout << ans << '\n';
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//  freopen("o1.txt","w",stdout);
#endif
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	Solve();
	return 0;
}

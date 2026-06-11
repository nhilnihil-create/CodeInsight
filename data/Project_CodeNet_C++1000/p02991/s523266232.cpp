#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;*/
//These are for segment tree
/*int op(int a, int b){return max(a, b);}
int e(){return -1;}
bool f(int v){ return v < target;}
*/
#pragma endregion
#pragma region macros
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#pragma endregion
#pragma region debug for var, v, vv
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){cout << endl;int cnt = 0;for(const auto& v : vv){cout << cnt << "th : "; view(v); cnt++;} cout << endl;}
#pragma endregion

const ll mod = 1000000007;
const int inf = 1001001001;
const ll INF = 1001001001001001001;
const int MAX = 2000005;

template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/*-----------------------------------------------------------------------------------------------------*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vvi G(3 * n);
	rep(i,m){
		int a, b; cin >> a >> b;
		--a; --b;
		for(int i = 0; i < 3; i++){
			G[a + i * n].push_back((b + (i + 1) * n) % (3 * n));
		}
	}
	int s, t; cin >> s >> t;
	s--; t--;
	queue<int> que;
	que.push(s);
	vi dist(3 * n, -1);
	dist[s] = 0;
	while(!que.empty()){
		int v = que.front(); que.pop();
		for(int nv : G[v]){
			if(dist[nv] != -1) continue;
			dist[nv] = dist[v] + 1;
			que.push(nv);
		}
	}
	if(dist[t] == -1) cout << -1 << endl;
	else cout << dist[t] / 3 << endl;
}
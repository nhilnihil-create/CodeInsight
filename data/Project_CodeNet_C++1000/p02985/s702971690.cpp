#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
/*#include <atcoder/modint>
using namespace atcoder;*/
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
const int MAX = 100005;

//using mint = modint998244353;
//using mint = modint1000000007;
//These are for segment tree
/*int op(int a, int b){return max(a, b);}
int e(){return -1;}
bool f(int v){ return v < target;}
*/

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}

/*--------------------------------------------------------------------------------------------------------------------------------*/
ll ans;
int n;
ll k;
vector<ll> degree;
vector<bool> used;

void dfs(const vector<vector<int>> &G, int p = -1, int v = 0){
	used[v] = true;
	if(p != -1){
		degree[v]++;
		degree[p]++;
		ans = ans * (k - degree[p]) % mod;
	}
	else ans *= k;
	for(auto nv : G[v]){
		if(used[nv]) continue;
		dfs(G, v, nv); 
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	degree.resize(n);
	vector<vector<int>> tree(n);
	for(int i = 0; i < n - 1; i++){
		int a, b; cin >> a >> b;
		a--; --b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	if(*max_element(all(degree)) >= k) ans = 0;
	else{
		ans = 1;
		degree.assign(n, 0);
		used.resize(n, false);
		dfs(tree);
	}
	cout << ans << endl;
} 
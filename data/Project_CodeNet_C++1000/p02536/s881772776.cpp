#include <bits/stdc++.h>
#include <atcoder/all>
#define INF 1000000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(lp, vec.size()) cout << vec[lp] << " "; print(""); 
#define show(x) cerr << #x << " = " << x << "\n";
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
#define pb(x) push_back(x)
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
using namespace atcoder;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
//using mint = modint998244353;
//ll mod = 998244353;
using mint = modint1000000007;
ll mod = 1000000007;

struct union_find{
 
	vl parent;
	vl sizes;
 
	void init(ll n) {
		rep(i, n) parent.push_back(i);
		rep(i, n) sizes.push_back(1);
	}
 
	ll root(ll n){
		if(parent[n] == n) return n;
		return parent[n] = root(parent[n]);
	}
 
	ll size(ll n) {
		return sizes[root(n)];
	}
 
	bool is_same(ll a, ll b){
		return root(a) == root(b);
	}
 
	void unite(ll a, ll b){
		if(is_same(a, b)) return;
		sizes[root(a)] += size(b);
		parent[root(b)] = root(a);
	}
	
	ll group_count(){
		ll ret = 0;
		rep(i, parent.size()) ret += (parent[i] == i);
		return ret;
	}
};
 
void Main(){

	ll N, M;
	cin >> N >> M;
	vvl v(M, vl(2));
	rep(i, M) cin >> v[i][0] >> v[i][1];
	
	union_find uf;
	uf.init(N);
	
	rep(i, M) uf.unite(v[i][0], v[i][1]);
	
	ll ans = uf.group_count() - 1;
	print(ans);

}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t = 1;
	//cin >> t;
	rep(i, t) Main();
	return 0;
	
}




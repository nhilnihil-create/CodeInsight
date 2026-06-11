#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops") 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
#define fr(i,a,b) for(int i = a ; i <= b ; ++i)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
using namespace __gnu_pbds;
using ordered_set =
 tree<int, null_type,less<int>,
 rb_tree_tag,tree_order_statistics_node_update>;
//find_by_order(k):returns iterator to kth element starting from 0
//order_of_key(k):returns count of elements strictly smaller than k
typedef long long ll;typedef pair<int, int> pii;
typedef vector<int> vi;typedef long double ld;
template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T>>; 
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
template<class T> void re(T& x) { cin >> x; }
template<typename T> 
void remdup(vector<T>& v) {
	sort(all(v)); v.erase(unique(all(v)), v.end());
}
template<typename T> void re(vector<T> &v) {trav(i,v) cin >> i;}
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
#ifdef np
#include "/home/o_o/MyCodes/pr.h"
#else
#define trace(...)
#endif

#define MOD 1000000007  
//ref~ https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/DSU/DSU%20(7.6).h
struct DSU {
	vi e; void init(int n) { e = vi(n,-1); }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); } 
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	bool unite(int x, int y) { // union-by-rank
		x = find(x), y = find(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};
/**template<class T> T kruskal(int n, vector<pair<T,pii>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(n+1); // edges that unite are in MST
	trav(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/

void solve(){
	int n , m ;
	re(n,m);
	DSU d;
	d.init(n);
	while(m--){
		int a , b; 
		re(a,b);
		a--;b--;
		d.unite(a,b);
	}
	int cnt =0 ; 
	rep(i,0,n){
		cnt = max(cnt,d.size(i));
	}
	cout << cnt << endl; 
}

signed main() {
	unsyncIO();
	int tt =1 ;
	// cin >> tt;
	rep(i,0,tt) solve();













#ifdef np
	cout <<endl<<endl<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = inx(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "; print("");
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

struct union_find{

  vl parent;
  vl sizes;

  void init(ll n) {
    rep(i, n) parent.push_back(i);
	rep(i, n) sizes.push_back(1);
    return;
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
    return;
  }
};

void solve(){
	
	ll N, M, in1, in2;
	cin >> N >> M;	
	union_find uf;
	uf.init(N);
	rep(i, M){
		cin >> in1 >> in2;
		uf.unite(in1 - 1, in2 - 1);
	}
	ll ans = 0;
	rep(i, N) chmax(ans, uf.size(i));
	print(ans);
		
}	

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}




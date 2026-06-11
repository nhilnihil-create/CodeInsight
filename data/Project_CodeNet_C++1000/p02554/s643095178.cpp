#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


using namespace std;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define loop(i,n) for(int i=0;i<(int)(n);i++)
#define foi(i,k,n) for(int i=(k); i<(int)(n); i+=1)
#define fod(i,n,k) for(int i=k; i>=(int)n; i-=1)
#define fast_io ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define endl "\n"

#define int long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

#define fir first
#define sec second
#define pb push_back
#define mp make_pair

typedef long long llint;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<llint> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MII;
typedef set<int> SI;
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
llint toint(string s) {stringstream ss(s); llint x; ss >> x; return x;}
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//gp_hash_table<string, llint> table;


int mpow(llint base, llint exp) {
  base %= MOD;
  llint result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((llint)result * base) % MOD;
    base = ((llint)base * base) % MOD;
    exp >>= 1;
  }
  return result;
}


//void makegraph(int n, int m){
	//int i, u, v;
	//while(m--){
		//cin>>u>>v;
		//u--, v--;
		//g[u].pb(v);
		//g[v].pb(u);
	//}
//}

//void dfs(int u, int par){
	//for(int v:g[u]){
		//if (v == par) continue;
		//dfs(v, u);
	//}
//}


// ------------------------------------------------------------------ILB----------------------------------------------------------------  //

const int MX = 1e6 + 100;

//(n - 2)! * nP2

//int mpow(int x, int k){
	//x %= MOD;
	//int res = 1;
	//while(k){
		//if(k & 1) res *= x;
		//res %= MOD;
		//x *= x;
		//x %= MOD;
		//k >>= 1;
	//}
	//return (res%MOD);
//}


void solve(){
	int n;
	cin >> n;
	
	int ans = mpow(10, n) - 2 * mpow(9, n) + mpow(8, n);
	
	while(ans < 0) ans += MOD;
	
	cout << ans % MOD;
}




int32_t main() {
	fast_io;
    int t = 1;
    //cin >> t;
    //int xx = 0
    while(t--) {
		//xx++;
		//cout << "Case ";
      solve();
    }
    return 0;
}


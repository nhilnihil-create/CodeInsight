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


//int mpow(llint base, llint exp) {
  //base %= MOD;
  //llint result = 1;
  //while (exp > 0) {
    //if (exp & 1) result = ((llint)result * base) % MOD;
    //base = ((llint)base * base) % MOD;
    //exp >>= 1;
  //}
  //return result;
//}


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

const int MX = 2e5 + 100;



void solve(){
	int h, w, m;
	cin >> h >> w >> m;
	
	VI r(h + 1), c(w + 1); 
	set <PII> bomb;
	
	loop(i, m){
		int x, y;
		cin >> x >> y;
		bomb.insert({x, y});
		r[x]++;
		c[y]++;
	}
	
	VII rr, cc;
	
	loop(i, h + 1){
		if(r[i]) rr.pb({r[i], i});
	}
	
	loop(i, w + 1){
		if(c[i]) cc.pb({c[i], i});
	}
	
	sort(all(rr), greater <PII>());
	sort(all(cc), greater <PII>());
	
	int mx = rr[0].fir + cc[0].fir - bomb.count({rr[0].sec, cc[0].sec});
	int op = 0;
	
	for(int i = 0; i < rr.size(); ++i){
		if(op > 10000000) break;
		for(int j = 0; j < cc.size(); ++j){
			op++;
			if(op > 10000000) break;
			if(mx != rr[i].fir + cc[j].fir - (int)bomb.count({rr[i].sec, cc[j].sec})){
				mx = max(mx, rr[i].fir + cc[j].fir - (int)bomb.count({rr[i].sec, cc[j].sec}));
				//cout << mx;
				break;
			}
		}
	}
	
	cout << mx;
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


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


#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

#define fir first
#define sec second
#define pb push_back
#define mp make_pair

typedef long long int llint;
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


int n, k;
VI v;

bool bs(int x){
	int moves = 0;
	for(auto i : v){
		if(i <= x) break;
		int t = i / x;
		//if((i + t - 1) / t > x) t++;
		moves += t;
		if(moves > k) return false;
	}
	
	return true;
}


void solve(){
	cin >> n >> k;
	v.resize(n);
	
	loop(i, n) cin >> v[i];
	
	sort(all(v), greater<int>());
	int l = 0, r = *max_element(all(v));
	
	
	while(r - l > 1){
		int m = l + (r - l) / 2;
		bs(m) ? r = m : l = m;
	} 
	
	cout << r;
}




int main() {
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


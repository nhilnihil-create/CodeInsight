
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1000001; //check the limits, dummy
 
pi demap(int X) {
	int A = X % 1000;
	int B = X / 1000;
	return {B, A};
}
 
int mapTo(pi X) {
	return min(X.f, X.s)  + max(X.f, X.s)*1000;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int N; cin >> N;
	
	vector<vi> graph(MX);
	
	int ind[MX]; F0R(i, MX) ind[i] = 0;
	
	F0R(i, N) {
		int lst; cin >> lst; lst--;
		F0R(j, N-2) {
			int cur; cin >> cur; cur--;
			
			int ear = mapTo({i, lst});
			int lat = mapTo({i, cur});
			graph[ear].pb(lat);
			ind[lat]++;
			lst = cur;
		}
		
	}
	
	vi tbr;
	F0R(i, MX) if (ind[i] == 0) tbr.pb(i);
	
	int proc = 0;
	
	int day = 0;
	
	while (sz(tbr) != 0) {
		day++;
		proc += sz(tbr);
		
		vi nxtTbr;
		
		F0R(x, sz(tbr)) {
			//if (demap(tbr[x]).f < 4 && demap(tbr[x]).s < 4) cout << "on day " << day << " processed " << demap(tbr[x]).f << " " << demap(tbr[x]).s << endl;
			int i = tbr[x];
			F0R(y, sz(graph[i])) {
				int nxt = graph[i][y];
				ind[nxt]--;
				if (ind[nxt] == 0) nxtTbr.pb(nxt);
			}
			
		}
		
		tbr = nxtTbr;
	}
	
	if (proc != MX) {
		cout << -1 << endl;
	} else {
		cout << day << endl;
	}
	
	return 0;
}

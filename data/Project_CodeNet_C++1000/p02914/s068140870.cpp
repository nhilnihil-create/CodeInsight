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
const int MX = 100001; //check the limits, dummy

const int LOG_A = 60;
ll basis[LOG_A];

ll shifts[60];

void insertVector(ll mask) {
	for (int i = LOG_A - 1; i >= 0; i--) {
		if ((mask & shifts[i]) == 0) continue;

		if (!basis[i]) {
			basis[i] = mask;
			return;
		}

		mask ^= basis[i];
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	int N; cin >> N;
	
	ll data[N];
	shifts[0] = 1;
	FOR(i, 1, 60) shifts[i] = shifts[i-1]*2;
	ll totalXor = 0;
	F0R(i, N) {
		cin >> data[i];
		//insertVector(data[i]);
		totalXor ^= data[i];
	}
	ll z = 0;
	F0R(i, 60) {
		if (totalXor & shifts[i]) {
            z += shifts[i];
			F0R(j, N) {
				if (data[j] & shifts[i]) data[j] -= shifts[i];
			}
		}
	}
	
	F0R(i, N) insertVector(data[i]);
	
	ll ans = 0;
	
	F0Rd(i, 60) {
		if (!basis[i]) continue;
		if (ans & shifts[i]) continue;
		ans ^= basis[i];
	}
	
	cout << (2 * ans + z) << endl;
	//cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343

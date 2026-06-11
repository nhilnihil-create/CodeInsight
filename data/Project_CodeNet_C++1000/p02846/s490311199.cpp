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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll T1, T2, A1, A2, B1, B2; cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll D1 = A1 - B1, D2 = A2 - B2;
    if (D1 < 0) {
        D1 *= -1; D2 *= -1;
    }

    if (T1 * D1 + T2 * D2 > 0) {
        cout << 0 << endl; return 0;
    }
    if (T1 * D1 + T2 * D2 == 0) {
        cout << "infinity" << endl; return 0;
    }

    ll X = T1 * D1 + T2 * D2; X *= -1;
    ll Y = T1 * D1;
    ll ans = 2 * (Y / X) + 1;
    if (Y % X == 0) ans--;

    cout << ans << endl;


	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rb(i,x) for (auto& i : x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define UNIQUE(x) (x).resize(unique(all(x)) - begin(x))

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define F first
#define S second

#define pow10(n) stoll("1"+string(n,'0'))

#define debug(x) cout << ">>> " << #x << ": " << x << '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LNF = 1e18;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen((s+".in").c_str(),"r",stdin);
//	freopen((s+".out").c_str(),"w",stdout);
#endif
}

int main() {
    
    setIO("input");
    ll n; cin >> n;
    ll nodes = 0;
    for(ll i=1; i<=n; ++i)
        nodes += i * (n-i+1);
    ll edges = 0;
    for(ll i=1; i<=n-1; ++i) {
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        edges += u * (n-v+1);
    }
    cout << nodes - edges;
    
}

/*  ! CHECK THIS IF YOU GET IT WRONG !
	* int overflow, array bounds, NO VLAs
	* uninitialized local variables, rounding errors
	* intermediate result type, scientific
	* special cases (n = 0 or 1?)
	* reset your variables in scope
	* INF not large enough for ans, adding value to _MAX
	* using wrong variables, sorting extra 0s in global array
	* comment out input from file
	* operator precedence
*/
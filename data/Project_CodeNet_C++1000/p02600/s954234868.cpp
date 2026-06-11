#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define ALL(s) (s).begin(),(s).end()
#define ALLn(s,n) s,s+n
#define F first
#define S second
#define pb push_back
#define tc(t) int t; cin >> t; while(t--)
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n"; }

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const ll INF = LONG_LONG_MAX;

void solve() {
	int x;
	cin >> x;

	if(x >= 400 && x <600) cout << 8;
	else if(x >= 600 && x < 800) cout << 7;
	else if(x >= 800 && x < 1000) cout << 6;
	else if(x >= 1000 && x < 1200) cout << 5;
	else if(x >= 1200 && x < 1400) cout << 4;
	else if(x >= 1400 && x < 1600) cout << 3;
	else if(x >= 1600 && x < 1800) cout << 2;
	else {
		cout << 1;
	}
}

int32_t main() {_
	
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	// tc(t)
		solve();
	cerr << "[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
}


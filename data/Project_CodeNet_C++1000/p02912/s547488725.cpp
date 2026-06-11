#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define in insert
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define prec fixed << setprecision(12)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define test int t; cin >> t; while(t--)

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int, int> mii;
typedef vector<pii> vpi;

void solve() {
	int n, m;
	cin >> n >> m;
	int a;
	priority_queue<int> pq;
	rep(i, 1, n){
		cin >> a;
		pq.push(a);
	}
	rep(i, 1, m){
		if(sz(pq) == 0)
			break;
		int x = pq.top();
		pq.pop();
		if(x/2 >= 1){
			// cout << x;
			pq.push(x/2);
		}
	}
	int ans = 0;
	while(!pq.empty()){
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// test
	solve();

	return 0;
}
#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

void solve() {
	int n, m;
	cin >> n >> m;
	
	vii key(m);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		int msk = 0;
		for(int i = 0; i < b; i++) {
			int c;
			cin >> c;
			c--;
			
			msk |= (1 << c);
		}
		
		key[i] = {a, msk};
	}
	
	vi dp((1 << n), inf);
	dp[0] = 0;
	for(int msk = 0; msk < (1 << n); msk++) {
		for(int i = 0; i < m; i++) {
			if(dp[msk] == inf) continue;
			int nmsk = msk | key[i].ss;
			
			dp[nmsk] = min(dp[nmsk], dp[msk] + key[i].ff);
		}
	}
	
	cout << (dp[(1 << n) - 1] == inf ? -1 : dp[(1 << n) - 1]) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}
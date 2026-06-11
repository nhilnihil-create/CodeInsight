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
	int n, l;
	cin >> n >> l;
	
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		tot += l + i - 1;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int curr = tot - (l + i - 1);
		if(abs(tot - curr) < abs(tot - ans)) ans = curr;
	}
	
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}
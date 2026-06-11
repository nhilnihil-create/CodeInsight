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
	int n;
	cin >> n;
	
	vector<queue<int>> q(n);
	vvi a(n, vi(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - 1; j++) {
			int x;
			cin >> x;
			x--;
			
			q[i].push(x);
		}
	
	int ans = 0, ok = 1;
	while(ok) {
		vi vis(n, 0);
		ok = 0;
		for(int i = 0; i < n; i++) {
			if(q[i].empty()) continue;
			if(vis[i] || vis[q[i].front()]) continue;
			
			if(q[q[i].front()].front() == i) {
//				cout << ans + 1 << " " << q[i].front() << " " << q[q[i].front()].front() << endl;
				ok = 1;
				vis[q[i].front()] = 1;
				vis[q[q[i].front()].front()] = 1;
				q[q[i].front()].pop();
				q[i].pop();
			} 
		}
		
		ans += ok;
	}
	
	for(int i = 0; i < n; i++) {
		if(!q[i].empty()) {
			cout << -1 << endl;
			return;
		}
	}
	
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
 
constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;
 
int main() {
	int n;
	cin >> n;
 
	vector<queue<int>> vq(n);
 
	rep(i, n)rep(j, n - 1) {
		int a;
		cin >> a;a--;
		vq[i].push(a);
	}
 
	int k = 0;
	int ans = 0;
	int match = 0;
	bool uso = false;
 
	while (true) {
		int yester = match;
 
		vector<bool> game(n, false);
 
		rep(i, n) {
			if (vq[i].empty())continue;
			if (game[i])continue;
			int j = vq[i].front();
			if (i != vq[j].front())continue;
			if (game[j])continue;
 
			vq[i].pop();game[i] = true;
			vq[j].pop();game[j] = true;
			match++;
		}
 
 
		if (yester == match)break;
		ans++;
		if (ans == 200000) { uso = true;break; }
	}
 
	if (uso)cout << n * (n - 1) / 2 << endl;
	else if (match != n * (n - 1) / 2)cout << -1 << endl;
	else cout << ans << endl;
 
}

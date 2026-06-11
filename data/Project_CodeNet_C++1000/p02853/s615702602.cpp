#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	if (x == 1 && y == 1) {
		dunk(300000 * 2 + 400000);
		return 0;
	}
	if (x >= 4) x = 4;
	if (y >= 4) y = 4;
	int ans = 100000 * (4 - x) + 100000 * (4 - y);
	dunk(ans);
	return 0;
}
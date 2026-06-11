#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
#define int long long
#define vint vector<int>
#define pint pair<int, int>
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
#define dbg(x) cerr << #x << " = " << (x) << endl
#define yn(b) cout << ((b) ? "Yes" : "No") << endl
#define YN(b) cout << ((b) ? "YES" : "NO") << endl

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int ans = N / 2;

	if (N % 2 == 0) {
		ans--;
	}

	cout << ans << endl;

	return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define x_ real()
#define y_ imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
pair<int, int> dirs[] = { {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };
const ld eps = 1e-6;
const int N = 2e5 + 7;
string s;

int dp[N][27][27];

int solve(int idx, char prev1, char prev2) {
	if (idx == s.size())
		return 0;

	string p;
	if (prev1 >= 'a' && prev1 <= 'z')
		p += prev1;
	if (prev2 >= 'a' && prev2 <= 'z')
		p += prev2;

	int& ans = dp[idx][prev1-'a'][prev2-'a'];
	if (~ans)
		return ans;
	ans = -N - 15;
	if (idx != s.size() - 1) {
		if (s.substr(idx, 2) != p) {
			ans = max(ans, 1+solve(idx+2, s.substr(idx, 2)[0], s.substr(idx, 2)[1]));
		}
		if (s.substr(idx, 1) != p)
			ans = max(ans, 1+solve(idx+1, 'z'+1, s.substr(idx, 1)[0]));
	}
	else {
		if (s.substr(idx, 1) != p)
			ans = max(ans, 1+solve(idx+1, 'z'+1, s.substr(idx, 1)[0]));
	}
	return ans;
}



int main() {
	fastIO;
	cin >> s;
	memset(dp, -1, sizeof dp);
	cout << solve(0, 'z'+1, 'z'+1);

}

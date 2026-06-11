#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define x_ real()
#define y_ imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
//pair<int, int> dirs[] = { {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };
const ll mod = 1e9 + 7;
const ll N = 3e5 + 7;

ll ncr[2007][2007];
void pre() {
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == 0) {
				ncr[i][j] = 1;
			}
			else {
				ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
			}
		}
	}
}


int main() {
	fastIO;
	pre();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		ll ans = (ncr[n - k + 1][i] * ncr[k - 1][i - 1]) % mod;
		cout << ans << '\n';
	}


}

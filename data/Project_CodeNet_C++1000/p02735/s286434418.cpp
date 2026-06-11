#include <vector>
#include <iostream>
using namespace std;
#define ll long long
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%I64d", &x)
#define ss(s) scanf("%s", s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1000000007;
template <typename T>
T abs(const T& x) { return x < 0 ? -x : x; }
#include <cmath>
#include <algorithm>

void min_self(int& a, int b) {
	a = min(a, b);
}

const int INF = 1E9;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> grid(H);
	for (int row = 0; row < H; row++) {
		cin >> grid[row];
	}
	vvi dp(H, vector<int>(W, INF));

	dp[0][0] = (grid[0][0] == '#');
	for (int r = 0; r < H; ++r) {
		for (int c = 0; c < W; ++c) {
			if (r == 0 && c == 0) continue;
			if (r != 0) {
				min_self(dp[r][c], dp[r - 1][c] + (grid[r][c] == '#' && grid[r - 1][c] == '.'));
			}
			if (c != 0) {
				min_self(dp[r][c], dp[r][c - 1] + (grid[r][c] == '#' && grid[r][c - 1] == '.'));

			}
		}
	}
	int answer = dp[H - 1][W - 1];
	cout << answer << endl;
}

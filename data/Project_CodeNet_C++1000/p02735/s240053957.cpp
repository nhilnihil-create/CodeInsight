#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<ctime>
#include<cassert>
#include<complex>
#include<string>
#include<cstring>
#include<chrono>
#include<random>
#include<bitset>
#include<iomanip>

#define x first
#define y second
#define mp make_pair
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int MAX_N = 105, inf = 1e9;

int n, m;
string a[MAX_N];
int dp[MAX_N][MAX_N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 && j == 0) {
				dp[i][j] = (a[i][j] == '#');
				continue;
			}
			dp[i][j] = inf;
			if (i - 1 >= 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + (a[i][j] == '#' && a[i - 1][j] == '.'));
			}
			if (j - 1 >= 0) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + (a[i][j] == '#' && a[i][j - 1] == '.'));
			}
		}
	}	
	cout << dp[n - 1][m - 1] << "\n";
	return 0;
}
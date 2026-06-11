#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define ff first
#define ss second
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int main() {

	long long n, T; cin >> n >> T;
	vector < pair<long long, long long>> v(n);
	for (long long i = 0; i <= n - 1; i++) cin >> v[i].ff >> v[i].ss;
	sort(v.begin(), v.end());

	vector<long long> dp(T + (*(max_element(v.begin(), v.end()))).ff + 1, -1);
	dp[0] = 0;

	for (long long i = 0; i <= n - 1; i++) {
		for (long long j = T - 1; j >= 0; j--) {
			if (dp[j] == -1) continue;
			dp[j + v[i].ff] = max(dp[j + v[i].ff], dp[j] + v[i].ss);
		}
	}
	cout << *max_element(dp.begin(), dp.end());

	return 0;
}
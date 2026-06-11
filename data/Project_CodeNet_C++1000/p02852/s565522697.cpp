#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
#include <chrono>
#include <random>
#include <ctime>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = 3.14159265358979323846;
const ll MOD = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	string s;
	cin >> n >> m >> s;
	n++;
	vector<int> dp(n, INT32_MAX), pred(n, -1);
	dp[0] = 0;
	set<pair<int, int>> mins;
	mins.insert({ 0, 0 });
	for (int i = 1; i < n; i++) {
		if (i >= m + 1) {
			mins.erase({ dp[i - m - 1], i - m - 1 });
		}
		if (s[i] == '1') {
			dp[i] = INT32_MAX;
			mins.insert({ INT32_MAX, i });
		}
		else {
			if (mins.begin()->first != INT32_MAX) {
				dp[i] = mins.begin()->first + 1;
				pred[i] = mins.begin()->second;
			}
			mins.insert({ dp[i], i });
		}
	}
	if (dp[n - 1] == INT32_MAX) {
		cout << -1;
	}
	else {
		vector<int> ans;
		for (int i = n - 1; pred[i] != -1; i = pred[i]) {
			ans.push_back(i - pred[i]);
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
	}
}
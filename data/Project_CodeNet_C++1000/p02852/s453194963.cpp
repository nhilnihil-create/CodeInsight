#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int count_max = 0;
	int count_tmp = 0;
	rep(i, n + 1) {
		if(s[i] == '1') {
			count_tmp++;
			count_max = max(count_tmp, count_max);
		}
		else {
			count_tmp = 0;
		}
	}
	if(count_max >= m) {
		cout << -1 << endl;
		return 0;
	}

	vi dp(n + 1, -1);
	dp[n] = 0;
	int step = 0, pos = n;
	bool reached = false;
	while(!reached) {
		int next_pos = pos;
		step++;
		for(int i = 1; i <= m; i++) {
			if(pos - i < 0) break;
			dp[pos - i] = step;
			if(s[pos - i] == '0') next_pos = pos - i;
			if(pos - i == 0) reached = true;
		}
		pos = next_pos;
	}
	pos = 0;
	step = dp[pos];
	vi ans;
	for(step = dp[pos] - 1; step >= 0; step--) {
		int pre_pos = pos;
		while(dp[pos] != step) pos++;
		ans.push_back(pos - pre_pos);
	}
	rep(i, ans.size()) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}

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
	vi dp(n + 1, -1);
	dp[n] = 0;
	int step = 0, pos = n;
	bool reached = false;
	bool next_step = true;
	while(!reached && next_step) {
		while(pos > 0 && dp[pos] == step) pos--;
		pos++;
		while(pos < n && s[pos] == '1') pos++;
//		cout << step << ' ' << pos << endl;
		step++;
		next_step = false;
		for(int j = 1; j <= m; j++) {
			if(pos - j >= 0) {
				dp[pos - j] = step;
				if(s[pos - j] == '0') next_step = true;
			}
			if(pos - j == 0) {
				reached = true;
				break;
			}
		}
		pos--;
	}
	if(!reached) {
		cout << -1 << endl;
		return 0;
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

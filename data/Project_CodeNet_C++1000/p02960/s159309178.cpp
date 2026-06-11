#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;



int main() {
	string s;
	cin >> s;
	int size = s.size();
	vector<ll> dp(13, 0);
	dp[0] = 1;

	for(char c : s) {
		vector<ll> ndp(13, 0);
		rep(i, 10) if (c == '?' || c - '0' == i) rep(j, 13) {
			int d  = (j * 10 + i) % 13;
			ndp[d] = dp[j] + ndp[d];
			ndp[d] %= mod; 
		}
		dp = move(ndp);
	}


	cout << dp[5] << endl;

	return 0;
}

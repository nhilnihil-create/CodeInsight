

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const ll MOD = 2019;


int main(int argc, char* argv[]) {
	
	string s;
	cin >> s;

	vector<int> dp(s.length() + 1);

	int p10 = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		dp[i] = (dp[i + 1] + p10 * (s[i] - '0')) % MOD;
		p10 = (p10 * 10) % MOD;
	}

	map<int, int> m;
	for (int d : dp) {
		m[d]++;
	}

	int ans = 0;
	for (int i = 0; i < MOD; i++) {
		ans += (m[i] * (m[i] - 1)) / 2;
	}

	cout << ans << endl;
}
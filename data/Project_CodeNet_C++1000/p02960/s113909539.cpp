#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long dp[100010][15] = { 0 };
int main() {
	string s;
	cin >> s;
	dp[0][0] = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 13; k++) {
					dp[i + 1][(j + k * 10) % 13] = (dp[i + 1][(j + k * 10) % 13] + dp[i][k]) % 1000000007;
				}
			}
		}
		else {
			int x = s[i] - '0';
			for (int j = 0; j < 13; j++) {
				dp[i + 1][(x + j * 10) % 13] = (dp[i + 1][(x + j * 10) % 13] + dp[i][j]) % 1000000007;
			}
		}
	}
	cout << dp[s.size()][5] << endl;
	return 0;
}

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
int co[10][10] = { 0 };
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		int l = int(s[0] - '0');
		int r = int(s[s.size() - 1] - '0');
		co[l][r]++;
	}
	int ans = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			ans += co[i][j] * co[j][i];
		}
	}
	cout << ans << endl;
	return 0;
}
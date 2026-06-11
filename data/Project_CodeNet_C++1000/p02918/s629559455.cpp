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
vector<int> vec;
int c[100010] = { 0 };
int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int co = 1;
	vec.emplace_back(0);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) {
			vec.emplace_back(co);
			co = 1;
		}
		else {
			co++;
			c[i + 1]++;
		}
		c[i + 1] += c[i];
	}
	c[n] += c[n - 1];
	vec.emplace_back(co);
	for (int i = 1; i < vec.size(); i++) {
		vec[i] += vec[i - 1];
	}
	if (vec.size() <= k * 2 + 1) {
		cout << vec[vec.size() - 1] - vec[0] - 1 << endl;
		return 0;
	}
	else {
		int ans = 0;
		for (int i = 2 * k + 1; i < vec.size(); i++) {
			int ans1 = vec[i] - vec[i - 2 * k - 1] + c[vec[i - 2 * k - 1]] + c[n - 1] - c[vec[i]];
			if (ans < ans1) {
				ans = ans1;
			}
		}
		cout << ans - 1 << endl;
	}
	return 0;
}

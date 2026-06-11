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
vector<vector<int>> vec(30);
int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	s = s + s;
	for (int i = 0; i < s.size(); i++) {
		vec[int(s[i] - 'a')].emplace_back(i);
	}
	long long ans = 0;
	int now = -1;
	for (int i = 0; i < t.size(); i++) {
		auto itr = upper_bound(vec[int(t[i] - 'a')].begin(), vec[int(t[i] - 'a')].end(), now);
		if (itr == vec[int(t[i] - 'a')].end()) {
			cout << "-1" << endl;
			return 0;
		}
		ans += *itr - now;
		now = *itr % n;
	}
	cout << ans << endl;
	return 0;
}

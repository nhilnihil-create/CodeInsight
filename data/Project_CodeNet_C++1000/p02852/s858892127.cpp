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
int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> vec;
	int c = 1;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) {
			vec.emplace_back(c);
			c = 1;
		}
		else {
			c++;
		}
	}
	vec.emplace_back(c);
	for (int i = 0; i < vec.size(); i++) {
		if (i % 2 == 1) {
			if (vec[i] >= m) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	vector<int> a;
	int now = vec.size() - 1;
	int co = m, ans = 0;
	for (now; now >= 0; now--) {
		if (now % 2 == 1) {
			co -= vec[now];
			if (co <= 0) {
				a.emplace_back(ans);
				co = m;
				ans = 0;
				now++;
				continue;
			}
			ans += vec[now];
		}
		else {
			if (co <= vec[now]) {
				vec[now] -= co;
				a.emplace_back(m);
				co = m;
				ans = 0;
				now++;
				continue;
			}
			else {
				co -= vec[now];
				ans += vec[now];
			}
		}
	}
	if (ans != 0) {
		a.emplace_back(ans);
	}
	for (int i = a.size() - 1; i >= 0; i--) {
		cout << a[i];
		if (i != 0) {
			cout << " ";
		}
	}
	cout << endl;
}
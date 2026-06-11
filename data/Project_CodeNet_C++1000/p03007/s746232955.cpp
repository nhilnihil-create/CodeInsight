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
vector<int> vec, vec1;
vector<pair<int, int>> ans;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a >= 0) {
			vec.emplace_back(a);
		}
		else {
			vec1.emplace_back(a);
		}
	}
	if (vec.empty()) {
		sort(vec1.rbegin(), vec1.rend());
		for (int i = 1; i < n; i++) {
			ans.emplace_back(make_pair(vec1[0], vec1[i]));
			vec1[0] -= vec1[i];
		}
		cout << vec1[0] << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
		return 0;
	}
	if (vec1.empty()) {
		sort(vec.begin(), vec.end());
		for (int i = 1; i < n - 1; i++) {
			ans.emplace_back(make_pair(vec[0], vec[i]));
			vec[0] -= vec[i];
		}
		ans.emplace_back(make_pair(vec[n - 1], vec[0]));
		vec[n - 1] -= vec[0];
		cout << vec[n - 1] << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
		return 0;
	}
	sort(vec.begin(), vec.end());
	sort(vec1.begin(), vec1.begin());
	for (int i = 0; i < vec.size() - 1; i++) {
		ans.emplace_back(make_pair(vec1[0], vec[i]));
		vec1[0] -= vec[i];
	}
	for (int i = 0; i < vec1.size(); i++) {
		ans.emplace_back(make_pair(vec[vec.size() - 1], vec1[i]));
		vec[vec.size() - 1] -= vec1[i];
	}
	cout << vec[vec.size() - 1] << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
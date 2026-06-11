#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long int res = 0;
	vector<int> pre_v1(n, n), pre_v2(n, n);
	vector<int> post_v1(n, -1), post_v2(n, -1);
	vector<int> s1;
	set<pair<int, int>> s2;
	for (int i = 0; i < n; i++) {
		while (s2.size() > 0 && s2.begin()->first < v[i]) {
			pre_v2[s2.begin()->second] = i;
			s2.erase(*s2.begin());
		}
		
		while (s1.size() > 0 && v[s1.back()] < v[i]) {
			pre_v1[s1.back()] = i;
			s2.insert(make_pair(v[s1.back()], s1.back()));
			s1.pop_back();
		}
		s1.push_back(i);
	}
	s1.clear();
	s2.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (s2.size() > 0 && s2.begin()->first < v[i]) {
			post_v2[s2.begin()->second] = i;
			s2.erase(*s2.begin());
		}
		
		while (s1.size() > 0 && v[s1.back()] < v[i]) {
			post_v1[s1.back()] = i;
			s2.insert(make_pair(v[s1.back()], s1.back()));
			s1.pop_back();
		}
		s1.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		// cout << pre_v1[i] << " " << pre_v2[i] << " " << post_v1[i] << " " << post_v2[i] << endl;
		long long int l = (long long int)v[i] * (long long int)(pre_v2[i] - pre_v1[i]) * (i - post_v1[i]);
		long long int r = (long long int)v[i] * (long long int)(pre_v1[i] - i) * (post_v1[i] - post_v2[i]);
		res += l + r;
	}
	cout << res << endl;
}

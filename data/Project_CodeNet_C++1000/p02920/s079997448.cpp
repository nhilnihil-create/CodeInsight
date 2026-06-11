#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	int n = 1 << k;
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		s.insert(cur * (-1));
	}
	multiset<int> vals;
	vals.insert(*s.begin());
	s.erase(s.begin());
	for (int j = 0; j < k; j++) {
		vector<int> newVals;
		for (auto x : vals) {
			auto it = s.upper_bound(x);
			if (it == s.end()) {
				return cout << "No", 0;
			}
			newVals.push_back(*it);
			s.erase(it);
		}
		for (int i = 0; i < newVals.size(); i++) {
			vals.insert(newVals[i]);
		}
	}
	cout << "Yes";
	return 0;
}
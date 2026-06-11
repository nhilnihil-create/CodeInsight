#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	multiset<int> s;
	int m = 0;
	for (int i = 0; i < 1<<n; ++i)
	{
		int x; cin >> x;
		s.insert(x);
		m = max(m, x);
	}
	vector<int> exist;
	exist.push_back(m);
	s.erase(s.lower_bound(m));

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < 1<<i; ++k)
		{
			int j = exist[k];
			auto it = s.lower_bound(j);
			if (it == s.begin()) {
				cout << "No" << endl;
				return 0;
			}
			else {
				it--;
				int v = *it;
				exist.push_back(v);
				s.erase(it);
			}
		}
	}
	cout << "Yes" << endl;

	return 0;
}
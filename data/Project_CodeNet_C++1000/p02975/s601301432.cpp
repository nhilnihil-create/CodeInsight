#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	set<int> b;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		b.insert(a[i]);
	}
	sort(a.begin(), a.end());

	if (b.size() > 3) {
		cout << "No" << endl;
	} else if (b.size() == 3) {
		if (n % 3 != 0) {
			cout << "No" << endl;
		} else {
			vector<pair<int, int>> v;
			v.emplace_back(make_pair(a[0], 1));

			for (int i = 1; i < n; i++) {
				if (a[i - 1] == a[i]) {
					v[v.size() - 1].second++;
				} else {
					v.emplace_back(make_pair(a[i], 1));
				}
			}

			if ((v[0].first ^ v[1].first) == v[2].first && v[0].second * 3 == n && v[1].second * 3 == n) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	} else if (b.size() == 2) {
		if (n % 3 != 0) {
			cout << "No" << endl;
		} else {
			vector<pair<int, int>> v;
			v.emplace_back(make_pair(a[0], 1));

			for (int i = 1; i < n; i++) {
				if (a[i - 1] == a[i]) {
					v[v.size() - 1].second++;
				} else {
					v.emplace_back(make_pair(a[i], 1));
				}
			}

			if (v[0].first == 0 && v[0].second * 3 == n) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	} else {
		if (a[0] == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	
	
	return 0;
}
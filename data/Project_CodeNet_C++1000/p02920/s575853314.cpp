#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int N = pow(2, n);
	multiset<int> data;
	for (int i = 0; i < N; i++){
		int val;
		cin >> val;
		val = val * -1;
		data.insert(val);
	}
	
	vector<int> v;
	v.push_back(*data.begin());
	data.erase(data.begin());

	for (int i = 1; i <= n; i++) {
		vector<int> newv;
		for (auto it : v) {
			if (data.upper_bound(it) == data.end()) {
				cout << "No" << endl; 
				return 0;
			} 
			newv.push_back(*data.upper_bound(it));
			data.erase(data.upper_bound(it));
		}

		for (auto it : newv) {
			v.push_back(it);
		}
	}

	cout << "Yes" << endl;
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

void show(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << v[i];
	}
	cout << endl;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	vector<int> v;
	v = a;
	for (int i = 0; i < k; i++) {
		vector<int> w;
		w.assign(n + 1, 0);

		for (int j = 0; j < n; j++) {
			int l = max(0, j - v[j]);
			int r = min(n, j + v[j] + 1);

			w[l]++;
			w[r]--;
		}

		v.assign(n, 0);
		v[0] = w[0];
		for (int j = 0; j < n; j++) {
			v[j] = v[j-1] + w[j];
		}

		if(all_of(v.begin(), v.end(), [&n](const int &x){return x == n;})) {
			break;
		}

	}
	show(v);
	return 0;
}

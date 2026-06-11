#include "bits/stdc++.h"
using namespace std;

//48
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	v[0]--;
	for (int i = 1; i < n; ++i) {
		if (v[i] < v[i - 1]) {
			cout << "No";
			return 0;
		}else if (v[i] > v[i - 1]) {
			v[i]--;
		}
	}
	cout << "Yes";
}

#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int z = 0;
	set<int> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) z++;
		st.insert(a[i]);
	}

	if (z == n) {
		cout << "Yes" << endl;
		return 0;
	}
	

	if (st.size() == 2 && n % 3 == 0) {
		if (z == n / 3) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	if (st.size() == 3) {
		sort(a.begin(), a.end());
		if (a[n / 3 - 1] != a[n / 3] && a[n / 3 * 2 - 1] != a[n / 3 * 2] && ((a[0] ^ a[n / 3]) == a[n - 1])) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
	
	
	return 0;
}


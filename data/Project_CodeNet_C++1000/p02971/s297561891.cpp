#include "bits/stdc++.h"
using namespace std;

//39
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> pref(n);
	vector<int> suff(n);
	pref[0] = v[0];
	suff[n - 1] = v[n - 1];
	for (int i = 1; i < n; ++i) {
		pref[i] = max(v[i],pref[i - 1]);
		suff[n - i - 1] = max(v[n - i - 1],suff[n - i]);
	}
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			cout << suff[i + 1];
		}else if (i == n - 1) {
			cout << pref[i - 1];
		}else {
			cout << max(pref[i - 1],suff[i + 1]);
		}
		cout << endl;
	}
	//cout << ans;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	int fMx = b[n - 1];
    int SMx = b[n - 2];

	for (int i = 0; i < n; i++) {
		if (a[i] == fMx)
			cout << SMx << "\n";
		else 
			cout << fMx << "\n";
	}
	return 0;
}
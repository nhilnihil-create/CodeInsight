#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n - 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> c[i];
	}
	int sum = b[a[0]];
	int p = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] - 1 == p) {
			//cout << p << endl;
			sum += (a[i] - 1 >= 0) ? c[a[i] - 1] : 0;
		}
		sum += b[a[i]];
		p = a[i];
	}	
	cout << sum;
}


















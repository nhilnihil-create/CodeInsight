#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	double tmp = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		tmp += (double)1 / a;
	}
	cout << fixed << setprecision(11) << 1 / tmp << endl;
	return 0;
}
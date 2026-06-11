#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	long long a[n+1], sum = 0, res = 1;
	for(int i = 0; i < n+1; i++) {
		cin >> a[i];
		sum += a[i];
	}

	if(n == 0) {
		if(a[0] == 1) {
			cout << "1" << endl;
			return 0;
		}
		else {
			cout << "-1" << endl;
			return 0;
		}
	}
	else {
		if(a[0] >= 1) {
			cout << "-1" << endl;
			return 0;
		}
		long long h[n+1];
		h[0] = 1;
		for (int i = 1; i < n+1; i++)
		{
			if(a[i] > 2 * (h[i-1] - a[i-1])) {
				cout << "-1" << endl;
				return 0;
			}
			else {
				h[i] = min(sum, 2 * (h[i-1] - a[i-1]));
				res += h[i];
				sum -= a[i];
			}
		}
	}
	cout << res << endl;
	return 0;
}

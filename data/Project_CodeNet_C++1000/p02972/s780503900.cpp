#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> ans(n+1);
	for (int i = n; i >= 1; i--) {
		int sum = 0;
		for (int j = i+i; j <= n; j += i) {
			sum += ans[j];
		}
		sum %= 2;
		if (sum != a[i]) ans[i] = 1;
		else ans[i] = 0;
	}
	int m = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 1) m++;
	}
	cout << m << endl;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 1) cout << i << endl;
	}
	return 0;
}
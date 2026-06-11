#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << fixed << setprecision(6);
	while (cin >> n, n) {
		double ave = 0, res = 0;
		vector<int> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			ave += s[i];
		}
		ave /= n;
		for (int i = 0; i < n; i++) {
			res += (s[i] - ave) * (s[i] - ave);
		}
		cout << sqrt(res / n) << endl;
	}
	return 0;
}
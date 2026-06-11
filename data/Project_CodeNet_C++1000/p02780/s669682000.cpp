#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	double p[n];
	for(int i = 0; i < n; i++) {
		double q; cin >> q;
		p[i] = (q + 1) / 2;
	}

	double s[n];
	s[0] = p[0];
	for (int i = 1; i < n; i++)
	{
		s[i] = s[i-1] + p[i];
	}

	double res = s[k-1];
	for (int i = k; i < n; i++)
	{
		res = max(res, s[i] - s[i-k]);
	}
	cout << fixed << setprecision(12) << res << endl;
	return 0;
}


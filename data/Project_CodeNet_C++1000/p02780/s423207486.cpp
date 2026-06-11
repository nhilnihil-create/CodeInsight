#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	int p[n];
	long long s[n-k+1];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	s[0] = 0;
	for (int i = 0; i < k; i++)
		s[0] += p[i];
	for (int i = 1; i < n-k+1; i++) {
		s[i] = s[i-1] - p[i-1] + p[i+k-1];
	}
	long long max = s[0];
	for (int i = 0; i < n-k+1; i++) {
		if (s[i] > max)
			max = s[i];
	}
	cout << fixed << setprecision(10) << (max + k)/2.0 << endl;

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	long long a[n], sum[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i == 0) sum[i] = a[i];
		else sum[i] = sum[i-1] + a[i];
	}

	long long res = abs(sum[n-1] - 2 * sum[0]);
	for (int i = 1; i < n-1; i++)
	{
		res = min(res, abs(sum[n-1] - 2 * sum[i]));
	}

	cout << res << endl;
	return 0;
}

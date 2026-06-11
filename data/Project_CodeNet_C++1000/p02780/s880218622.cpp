#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	double arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] = (arr[i] + 1) / 2.0;
	}


	double sums[n + 1] = { 0 };
	for (int i = 1; i <= n; i++)
		sums[i] = sums[i - 1] + arr[i - 1];

	double ans = 0.0;

	for (int i = k; i <= n; i++) {
		ans = max(ans, sums[i] - sums[i - k]);
	}
	cout << setprecision(9) << ans << endl;
}

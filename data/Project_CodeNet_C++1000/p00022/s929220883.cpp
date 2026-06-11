#include <bits/stdc++.h>

using namespace std;

long maxSubArray(long arr[], int n)
{
	long maximum = arr[0];
	long currentMaximum = arr[0];
	long sum;
	for(int i = 1; i < n; i++) {
		sum = currentMaximum + arr[i];
		currentMaximum = max(arr[i], sum);
		maximum = max(maximum, currentMaximum);
	}
	return maximum;
}




int main()
{
	//freopen("input.txt", "r", stdin);
	long n;
	while(scanf("%ld", &n) == 1 && n != 0) {
		long arr[200001];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << maxSubArray(arr, n) << endl;
	}

	return 0;
}
#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int count = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] != arr[j] && arr[j] != arr[k]) {
					if (arr[i] + arr[j] > arr[k])
						count++;
				}
			}
		}
	}
	cout << count;
	return 0;
}
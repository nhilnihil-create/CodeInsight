#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;

int n, arr[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			for (int k = 1; k < j; ++k) {
				if (arr[i] == arr[j] || arr[i] == arr[k] || arr[j] == arr[k]) continue;
				int sum = arr[i] + arr[j] + arr[k];
				if (sum - max(arr[i], max(arr[j], arr[k])) > max(arr[i], max(arr[j], arr[k]))) ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
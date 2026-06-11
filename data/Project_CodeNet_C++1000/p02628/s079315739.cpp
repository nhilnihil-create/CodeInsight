#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main() {

	int n, k; cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int sum = 0;
	cout << accumulate(a, a+k, sum);

	return 0;
}
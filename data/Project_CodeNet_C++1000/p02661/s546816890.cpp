#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>

#define ll long long

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;

	int l, r;

	int a[200005], b[200005];

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	if (n % 2) {
		l = a[(n + 1) / 2];
		r = b[(n + 1) / 2];
	}
	else {
		l = a[n / 2] + a[n / 2 + 1];
		r = b[n / 2] + b[n / 2 + 1];
	}

	cout << r - l + 1 << endl;

	return 0;
}
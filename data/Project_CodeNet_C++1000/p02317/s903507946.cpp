#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	int n, a[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int L[MAX], l;
	L[0] = a[0];
	l = 1;
	for (int i = 1; i < n; i++) {
		if (L[l - 1] < a[i]) {
			L[l++] = a[i];
		} else {
			*lower_bound(L, L + l, a[i]) = a[i];
		}
	}
	cout << l << endl;
	return 0;
}


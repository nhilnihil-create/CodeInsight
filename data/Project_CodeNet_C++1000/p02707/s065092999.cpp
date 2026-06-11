#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

int main() {
	scanf("%d", &n);
	a.resize(n);
	for (int i = 1; i < n; i++) {
		int x; scanf("%d", &x);
		a[x - 1]++;
	}

	for (auto &x : a) printf("%d\n", x);
	return 0;
}
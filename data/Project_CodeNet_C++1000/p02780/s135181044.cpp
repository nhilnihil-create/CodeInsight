#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
int p[N];

int main() {

	int k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", p + i), p[i] += p[i - 1];

	int mx = 0;
	for(int i = k; i <= n; i++) {
		mx = max(mx, p[i] - p[i - k]);
	}

	mx += k;
	printf("%d.%d\n", mx / 2, mx % 2 ? 5 : 0);
}

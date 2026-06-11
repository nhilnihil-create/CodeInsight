#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;

int n, k;
int a[N];

bool f(int len) {
	ll cnt = 0;
	for(int i = 1; i <= n; i++) cnt += (a[i] + len - 1) / len - 1;
	return cnt <= k;
}

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++) scanf("%d", a + i);

	int lo = 1, hi = 1e9, ans = 0;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(f(mid)) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	printf("%d\n", ans);
}

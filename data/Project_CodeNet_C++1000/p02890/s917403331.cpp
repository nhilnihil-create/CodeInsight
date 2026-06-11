#include <bits/stdc++.h>

using namespace std;

int n;
int a[300005], cnt[300005], sum[300005];

bool solve(int s, int t) {
	int tot = 0;
	auto itr = lower_bound(a, a + n, s);
	
	if (itr == a + n) tot = sum[n - 1];
	else {
		int id = itr - a;
		if (id) tot += sum[id - 1];
		tot += (n - id) * s;
	}
	
	return tot >= 1LL * s * t;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		cnt[x]++;
	}
	
	for (int i = 0; i < n; i++) a[i] = cnt[i];
	
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) {
		sum[i] = a[i];
		if (i) sum[i] += sum[i - 1];
	}
	
	for (int k = 1; k <= n; k++) {
		int lb = 0;
		int ub = n + 1;
		
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (solve(mid, k)) lb = mid;
			else ub = mid;
		}
		
		printf("%d\n", lb);
	}
}

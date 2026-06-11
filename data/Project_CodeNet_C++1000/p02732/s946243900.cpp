#include <bits/stdc++.h>

using namespace std;

int a[200005], cnt[200005];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	
	long long res = 0;
	
	for (int i = 1; i <= n; i++) res += 1LL * cnt[i] * (cnt[i] - 1) / 2;
	
	for (int i = 0; i < n; i++) {
		int v = a[i];
		long long tmp = res;
		tmp -= 1LL * cnt[v] * (cnt[v] - 1) / 2;
		cnt[v]--;
		tmp += 1LL * cnt[v] * (cnt[v] - 1) / 2;
		cnt[v]++;
		
		printf("%lld\n", tmp);
	}
}

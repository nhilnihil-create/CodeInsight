#include <bits/stdc++.h>

using namespace std;

int a[200005];
unordered_map <int, int> cnt;

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	long long res = 0;
	
	for (int i = 0; i < n; i++) {
		res += cnt[i - a[i]];
		cnt[a[i] + i]++;
	}
	
	printf("%lld\n", res);
}

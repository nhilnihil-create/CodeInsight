#include <bits/stdc++.h>

using namespace std;

int cnt[200005];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	
	for (int i = 1; i <= n; i++) printf("%d\n", cnt[i]);
}

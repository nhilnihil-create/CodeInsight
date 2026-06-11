#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long k;
	int n;
	scanf("%d%lld", &n, &k);
	int a[210000];
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int h = 1;
	int height[210000];
	vector<bool> visited(n+1, false);
	int st = 1;
	while(k && !visited[st]) {
		visited[st] = true;
		height[st] = h;
		h++;
		k--;
		st = a[st];
	}
	if(k) {
		k %= (h-height[st]);
		while(k) {
			st = a[st];
			k--;
		}
	}
	printf("%d\n", st);
}
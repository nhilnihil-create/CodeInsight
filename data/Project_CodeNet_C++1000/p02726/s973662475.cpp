#include <bits/stdc++.h>

using namespace std;

int cnt[2005];

int main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int dist = j - i;
			
			dist = min(dist, abs(x - i) + 1 + abs(y - j));
			cnt[dist]++;
		}
	}
	
	for (int i = 1; i <= n - 1; i++) printf("%d\n", cnt[i]);
}

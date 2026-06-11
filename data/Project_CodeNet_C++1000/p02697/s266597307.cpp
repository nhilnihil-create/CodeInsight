#include <bits/stdc++.h>

using namespace std;


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	int odd = (m + 1) / 2;
	int even = m / 2;
	int cur = 1;
	
	for (int i = odd; i >= 1; i--) {
		printf("%d %d\n", cur, cur + i * 2 - 1);
		cur++;
	}
	
	cur = n;
	for (int i = even; i >= 1; i--) {
		printf("%d %d\n", cur - i * 2, cur);
		cur--;
	}
}

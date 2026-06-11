#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 15;
	for(int i=1; i<=5; i++) {
		int a;
		scanf("%d", &a);
		ans -= a;
	}
	printf("%d", ans);
	return 0;
}
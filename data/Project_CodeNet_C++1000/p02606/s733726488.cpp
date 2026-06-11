#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int L, R, d;
	scanf("%d %d %d", &L, &R, &d);
	int ans = 0;
	for (int i = L; i <= R; i++) {
		if (i % d == 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int a[200100];
	int ans = 0;
	int target = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] != target) {
			ans++;
		} else {
			target++;
		}
	}
	if (ans == N) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}

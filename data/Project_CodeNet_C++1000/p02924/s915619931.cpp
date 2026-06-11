#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	long ans = 0;
	for (int i = 1; i <= N - 1; i++) {
		ans += i;
	}
	printf("%ld", ans);
	return 0;
}

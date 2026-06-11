#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int H, W, N;
	scanf("%d %d %d", &H, &W, &N);
	printf("%d\n", (N + max(H, W) - 1) / max(H, W));
	return 0;
}

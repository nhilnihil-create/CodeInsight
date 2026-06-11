#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int H1, M1, H2, M2, K;
	scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &K);
	printf("%d\n", 60 * (H2 - H1) + (M2 - M1) - K);

	return 0;
}

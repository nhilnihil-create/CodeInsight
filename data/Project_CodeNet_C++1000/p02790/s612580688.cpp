#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	int m = min(a, b);
	int M = max(a, b);
	for (int i = 0; i < M; i++) {
		printf("%d", m);
	}


	return 0;
}

#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int a;
	scanf("%d", &a);
	printf("%d:",a);
	for (int b = 2; b <= sqrt(a); b++) {
		while (1) {
			if (a%b)break;
			a /= b;
			printf(" %d", b);
		}
	}
	if (a != 1)printf(" %d", a);
	printf("\n");
}
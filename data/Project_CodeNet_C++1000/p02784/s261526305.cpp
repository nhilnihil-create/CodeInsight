#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int H;
	int N;
	scanf("%d %d", &H, &N);
	for (int i = 0; i < N; i++) {
		int A;
		scanf("%d", &A);
		H -= A;
	}
	printf(H <= 0 ? "Yes" : "No");

	return 0;
}

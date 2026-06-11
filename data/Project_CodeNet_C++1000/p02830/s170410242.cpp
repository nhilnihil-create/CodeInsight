#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	string S, T;
	cin >> S >> T;
	for (int i = 0; i < N; i++) {
		printf("%c%c", S[i], T[i]);
	}
	printf("\n");

	return 0;
}

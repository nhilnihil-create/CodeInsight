#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	string S, T, U;
	cin >> S >> T;
	int A, B;
	scanf("%d %d", &A, &B);
	cin >> U;
	if (U == S) {
		A--;
	} else if (U == T) {
		B--;
	}
	printf("%d %d", A, B);

	return 0;
}

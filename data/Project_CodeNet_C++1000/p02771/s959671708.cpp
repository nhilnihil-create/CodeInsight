#include <bits/stdc++.h>

using namespace std;

int A[3];

int main(){
	scanf("%d %d %d", A, A + 1, A + 2);
	sort(A, A + 3);
	if (A[0] == A[2]) {
		printf("No\n");
	} else {
		if (A[1] == A[0] || A[1] == A[2]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}
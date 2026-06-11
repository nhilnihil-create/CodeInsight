#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	int A[100];
	int total = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		total += A[i];
	}
	int pop = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] >= total / (4. * M)) {
			pop++;
		}
	}

	if (pop >= M) {
		cout << "Yes" << endl;

	} else {
		cout << "No" << endl;
	}

	return 0;
}

#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	int H[100010];
	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}
	int A[100010], B[100010];
	set<int> badTowers;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		int H_A = H[A[i] - 1];
		int H_B = H[B[i] - 1];
		// cout << H_A << " " << H_B << endl;
		if (H_A == H_B) {
			badTowers.insert(A[i]);
			badTowers.insert(B[i]);
		} else if (H_A > H_B){
			badTowers.insert(B[i]);
		} else {
			badTowers.insert(A[i]);
		}
	}
	printf("%zu", N - badTowers.size());
	return 0;
}

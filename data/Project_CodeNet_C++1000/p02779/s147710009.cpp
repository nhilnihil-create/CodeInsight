#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int A[200100];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	int prev = 0;
	string ans = "YES";
	for (int i = 0; i < N; i++) {
		if (prev == A[i]) {
			ans = "NO";
			break;
		} else {
			prev = A[i];}
	}

	cout << ans << "\n";
	return 0;
}

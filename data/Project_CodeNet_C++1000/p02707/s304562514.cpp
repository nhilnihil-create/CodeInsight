#include <bits/stdc++.h>
using namespace std;
 
#define PI 3.14159265358979323846264338327950L

int main() {
	int N;
	cin >> N;
	int A[2 * 100000];
	memset(A, 0x00, sizeof(A));
	for (int ii = 0; ii < N - 1; ii++) {
		int temp;
		cin >> temp;
		A[temp - 1] += 1;
	}
	for (int ii = 0; ii < N; ii++) {
		cout << A[ii] << endl;
	}
	return 0;
}
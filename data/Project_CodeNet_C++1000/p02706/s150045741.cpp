#include <bits/stdc++.h>
using namespace std;
 
#define PI 3.14159265358979323846264338327950L

int main() {
	int N, M;
	cin >> N >> M;

	for (int ii = 0; ii < M; ii++) {
		int A;
		cin >> A;
		N = N - A;
		if (N < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << N << endl;
}
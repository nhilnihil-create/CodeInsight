#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int n = 0; n < N; ++n) {
		cin >> A[n];
	}
	vector<int>copyA = A;
	sort(copyA.begin(), copyA.end(), std::greater<int>());//降順ソート
	int top = copyA[0];
	int next = copyA[1];
	for (int n = 0; n < N; ++n) {
		if (top == A[n]) {
			cout << next <<endl;
		}
		else {
			cout << top << endl;
		}
	}
	return 0;
}

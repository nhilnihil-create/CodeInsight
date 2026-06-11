#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>A(N), B(N), C(N - 1);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		--A[i];
	}
	for (int j = 0; j < N; ++j) {
		cin >> B[j];
	}
	for (int k = 0; k < N; ++k) {
		cin >> C[k];
	}

	int answer = 0;

	for (int i = 0; i < N; ++i) {
		answer += B[A[i]];

		if (i > 0 && A[i] == A[i-1]+ 1) {
			answer += C[A[i - 1]];
		}
	}

	cout << answer << endl;

}
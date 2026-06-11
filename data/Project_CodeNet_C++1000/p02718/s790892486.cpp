#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N,M;
	double A[110] = {},sum = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}

	sort(A, A + N, greater<>());

	if (A[M - 1] >= sum / (4 * M)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}


	return 0;
}
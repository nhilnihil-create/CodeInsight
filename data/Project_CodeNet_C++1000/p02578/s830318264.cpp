#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N = 0;
	long long diff=0, step=0;
	cin >> N;
	vector <long long> A(N);

	for (int i = 0; i < N; i++){
		cin >> A[i];
		if (i != 0) {
			diff = A[i - 1] - A[i];
			if (diff > 0) {
				step += diff;
				A[i] += diff;
			}
		}
	}

	cout << step << endl;
	return 0;
}

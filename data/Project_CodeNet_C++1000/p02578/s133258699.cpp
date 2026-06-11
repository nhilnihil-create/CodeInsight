#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long N;
	cin >> N;
	vector<long long> A(N);
	for (long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long s = 0;
	for (long long i = 1; i < N; i++) {
		if (A[i - 1] > A[i]) {
			s += A[i - 1] - A[i];
			A[i] = A[i - 1];
		}
	}
	cout << s << endl;

	return 0;
}
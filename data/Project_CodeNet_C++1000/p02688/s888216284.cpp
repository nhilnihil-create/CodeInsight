#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<bool> A(N, false);
	for (int i = 0; i < K; i++) {
		int d;
		cin >> d;
		for (int j = 0; j < d; j++) {
			int a;
			cin >> a;
			a--;
			A[a] = true;
		}
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		if (!A[i]) count++;
	}

	cout << count << endl;

	return 0;
}
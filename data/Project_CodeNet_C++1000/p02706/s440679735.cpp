#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> VI;


int main() {
	int N, M;
	cin >> N >> M;

	VI A;
	for (int i = 0; i < M; ++i) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	int rem = N - accumulate(A.begin(), A.end(), 0);
	if (rem < 0) rem = -1;
	cout << rem << endl;

	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;


int main() {
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<int> p(N, 0);

	for (int i = 0; i < Q; ++i) {
		int A;
		cin >> A;
		p[A - 1]++;
	}

	for (int i = 0; i < N; ++i) {
		if (K > (Q - p[i])) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}

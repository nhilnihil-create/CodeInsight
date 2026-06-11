#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, A[1 << 18], B[1 << 18];
multiset<int> S;

int main() {
	cin >> N;
	for (int i = 0; i < (1 << N); i++) { cin >> A[i]; S.insert(A[i]); }
	sort(A, A + (1 << N));

	B[0] = A[(1 << N) - 1];
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j < (1 << i); j++) {
			auto itr = S.lower_bound(B[j]);
			if (itr == S.begin()) {
				cout << "No" << endl;
				return 0;
			}
			itr--;
			B[j + (1 << i)] = (*itr);
			S.erase(itr);
		}
	}
	cout << "Yes" << endl;
	return 0;
}
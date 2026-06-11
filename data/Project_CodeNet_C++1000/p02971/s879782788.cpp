#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<pair<int, int> > A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end(), greater<pair<int, int> >());
	for (int i = 0; i < N; ++i) {
		if (A[0].second != i) {
			cout << A[0].first << '\n';
		}
		else {
			cout << A[1].first << '\n';
		}
	}
	return 0;
}
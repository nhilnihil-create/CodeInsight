#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//see answer
int main() {
	long long N, K;
	cin >> N >> K;
	vector<long long> A(N), F(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> F[i];
	sort(A.begin(), A.end());
	sort(F.begin(), F.end(), greater<long long>());
	long long MIN = 0, MAX = A[N - 1] * F[0];
	while (MIN != MAX) {
		long long MID = MIN + (MAX - MIN) / 2ll;
		long long cost = 0;
		for (int i = 0; i < N; i++) cost += max(0ll, (A[i] * F[i] - MID + F[i] - 1) / F[i]);
		if (cost <= K) MAX = MID;
		else MIN = MID + 1;
	}
	cout << MIN << endl;
	return 0;
}
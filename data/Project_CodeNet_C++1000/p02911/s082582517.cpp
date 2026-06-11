#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long N, M, K; cin >> N >> M >> K;
	vector<long long>A(N, M);
	for (long long i = 0; i < K; i++) {
		long long B; cin >> B;
		A.at(B - 1)++;
	}
	for (long long i = 0; i < N; i++) {
		cout << (A.at(i) - K > 0 ? "Yes" : "No") << endl;
	}
}
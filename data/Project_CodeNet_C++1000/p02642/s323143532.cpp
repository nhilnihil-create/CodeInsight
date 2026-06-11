#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long N; cin >> N;
	vector<long long>A(N);
	vector<long long>InA(2000000, 0);
	for (long long i = 0; i < N; i++) {
		cin >> A.at(i);
		InA.at(A.at(i))++;
	}
	long long ans = 0;
	for (long long i = 0; i < N; i++) {
		long long num = 0;
		for (long long j = 1; j * j <= A.at(i); j++) {
			if (A.at(i) % j == 0) {
				num += InA.at(j);
				if (A.at(i) / j != j) num += InA.at(A.at(i) / j);
			}
		}
		if (num - 1 == 0) ans++;
	}
	cout << ans << endl;
}
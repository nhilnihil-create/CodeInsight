#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, M, S;
	multiset<long long> MS;
	vector<long long> V;
	cin >> N;
	M = 1LL << N;
	for (int i = 0; i < M; i++) cin >> S, MS.insert(S);
	auto it = MS.end();
	it--;
	V.push_back(*it);
	MS.erase(it);
	for (long long i = 0; i < N; i++) {
		long long L = 1LL << i;
		for (long long j = 0; j < L; j++) {
			auto it2 = MS.lower_bound(V[j]);
			if (it2 == MS.begin()) {
				cout << "No" << endl;
				return 0;
			}
			it2--;
			V.push_back(*it2);
			MS.erase(it2);
		}
		sort(V.begin(), V.end(), greater<long long>());
	}
	cout << "Yes" << endl;
}
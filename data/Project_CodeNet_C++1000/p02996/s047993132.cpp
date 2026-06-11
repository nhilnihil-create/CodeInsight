#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<long long, long long>>A(N);
	for (int n = 0; n < N; ++n) {
		long long a, b;
		cin >> a >> b;
		A[n] = make_pair(b,a);
	}
	sort(A.begin(),A.end());

	long long time = 0;
	for (int n = 0; n < N; ++n) {
		if (time + A[n].second > A[n].first) {
			cout << "No"<<endl;
			return 0;
		}
		time += A[n].second;
	}
	cout << "Yes" << endl;
	return 0;
}
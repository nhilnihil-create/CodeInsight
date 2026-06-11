#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	u64 N, K;
	cin >> N >> K;

	vector<u64> A(N);
	for(u64 i=0; i<N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end(), greater<u64>());

	u64 h = A[0];
	u64 l = 0;
	
	while(l + 1 < h) {
		u64 cnt = 0;
		u64 m = l + (h - l) / 2;

		for(u64 i=0; i<N && cnt<=K; i++) {
			cnt += (A[i] + m - 1) / m - 1;
		}

		if(K >= cnt) {
			h = m;
		} else {
			l = m;
		}
	}

	cout << h << endl;
	return 0;
}
#include <bits/stdc++.h>
#include <boost/math/common_factor.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	u64 N;
	cin >> N;

	s64 a_min = INT64_MAX;
	s64 a_max = INT64_MIN;
	s64 b_min = INT64_MAX;
	s64 b_max = INT64_MIN;

	for(u64 i=0; i<N; i++) {
		s64 x, y;
		cin >> x >> y;

		a_min = min(a_min, x + y);
		a_max = max(a_max, x + y);
		b_min = min(b_min, x - y);
		b_max = max(b_max, x - y);
	}

	s64 ans = max(a_max - a_min, b_max - b_min);
	cout << ans << endl;

	return 0;
}
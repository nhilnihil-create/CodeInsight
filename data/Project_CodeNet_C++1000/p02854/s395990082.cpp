#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll n; scanf("%lld", &n);
	ll A[n]; for (ll i = 0; i < n; ++i) scanf("%lld", &A[i]);

	ll first_sum = A[0], first_idx = 0;
	ll second_sum = A[n - 1], second_idx = n - 1;

	while (second_idx - first_idx != 1) {
		if (first_sum <= second_sum) {
			++first_idx;
			first_sum += A[first_idx];
		}
		else {
			--second_idx;
			second_sum += A[second_idx];
		}
	}

	printf("%lld\n", abs(first_sum - second_sum));
	return 0;
}
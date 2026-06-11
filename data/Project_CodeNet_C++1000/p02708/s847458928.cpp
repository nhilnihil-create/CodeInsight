#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>

#include <sstream>
#include <bitset>

using namespace std;
long long MOD = 1000000007LL;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX  2147483647

int main() {
	int N, K;
	cin >> N >> K;
    ++N;

	long long ans = 1;



	for (long long i = K; i < N; ++i) {
        long long buf1 = i * (i - 1) / 2;
        long long buf2 = i * (N - i) + buf1;
        ans = (ans + (buf2 - buf1) + 1) % MOD;
	}

	cout << ans << endl;
	return 0;
}
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

template<class T>
map<T, int> prime_factorization(T n) {
	map<T, int> ret;

	for (long long i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}

	if (n != 1)ret[n] = 1;
	return ret;
}


int main() {

	long long l, r;
	cin >> l >> r;

	if (l / 2019 != r / 2019) {
		cout << 0 << endl;
		return 0;
	}

	long long ans = INT_MAX;
	for (long long i = l; i <= r; ++i) {
		for (long long j = i + 1; j <= r; ++j) {
			ans = min(ans, (i * j) % 2019);
		}
	}

	cout << ans << endl;
	return 0;
}

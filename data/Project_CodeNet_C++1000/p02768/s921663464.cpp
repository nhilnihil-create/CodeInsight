#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>



using namespace std;

int64_t mpow(int64_t a, int64_t b) {
	int64_t mod = pow(10, 9) + 7;
	int64_t res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}

int64_t combination(int64_t n, int64_t k) {
	int64_t mod = pow(10, 9) + 7;
	if (k > n / 2)k = n - k;
	int64_t bunbo=1,bunsi=1;
	if (k == 0) {
		return 1;
	}
	int64_t i = 0;
	
	while (k != 0) {

		bunbo *=  k;
		bunsi *= n - i;
		bunbo %= mod;
		bunsi %= mod;
		i++;
		k--;
	}
	
	
	return (bunsi*mpow(bunbo,mod-2))%mod;
}

int main() {

	int64_t mod = pow(10, 9) + 7;
	int64_t n, a, b;
	cin >> n>>a>>b;
	int64_t ans;
	ans = mpow(2, n)-1;

	ans -= combination(n, a) + combination(n, b);

	while (ans < 0) {
		ans += mod;
	}
	cout << ans;

}


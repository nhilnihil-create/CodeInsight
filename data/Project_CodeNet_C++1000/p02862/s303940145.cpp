#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using LL = long long;
using Graph = vector<vector<int>>;
#define NUM 1000000007

LL pow_l(LL x, LL n) {
	LL ans = 1;
	LL x_n = x;
	while (n > 0) {
		if ((n & 1) == 1) {
			ans = ans * x_n % NUM;
		}
		n = n >> 1;
		x_n = x_n * x_n % NUM;
	}
	return ans;
}



int main() {
	LL X, Y;
	cin >> X >> Y;
	if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	LL a = (2 * Y - X) / 3;
	LL b = (2 * X - Y) / 3;
	if (a < 0 || b < 0) {
		cout << 0 << endl;
		return 0;
	}
	vector<LL>  kaijo(3e6 + 10), inv_kaijo(3e6 + 10), inv(3e6 + 10);
	kaijo[1] = 1;
	inv_kaijo[1] = 1;
	inv[1] = 1;
	kaijo[0] = 1;
	inv_kaijo[0] = 1;
	inv[0] = 1;
	for (int i = 2; i <= 2e6; i++) {
		kaijo[i] = kaijo[i - 1] * i % NUM;
		inv[i] = NUM - inv[NUM % i] * (NUM / i) % NUM;
		inv_kaijo[i] = inv_kaijo[i - 1] * inv[i] % NUM;
		//inv_kaijo[i] = inv_kaijo[i - 1] * pow_l(i, NUM - 2) % NUM;
	}

	LL ans = kaijo[a + b] * inv_kaijo[a] % NUM * inv_kaijo[b] % NUM;
	cout << ans << endl;
	return 0;






}
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

// 2 で割り切れる回数を返す
int f(int x) {
	int res = 0;
	while (x % 2 == 0) {
		x /= 2;
		res++;
	}
	return res;
}

// 最大公約数を返す
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

// 最小公倍数を返す
long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

int main() {

	int N, M;
	cin >> N >> M;

	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	// 入力を 2 で割る
	for (int i = 0; i < N; i++) {
		if (a[i] % 2 == 1) {
			cout << 0 << endl;
			return 0;
		}
		a[i] /= 2;
	}

	// 2 で割り切れる回数が a[0] から a[N - 1] まで、全部同じじゃないとダメ
	// 同じ場合は、2^t で割る
	int t = f(a[0]);
	for (int i = 0; i < N; i++) {
		if (f(a[i]) != t) {
			cout << 0 << endl;
			return 0;
		}
		// a[i] /= 2^t
		a[i] >>= t;
	}

	// M /= 2^t
	M >>= t;

	// 2^t で割った a[0] から a[N - 1] までの lcm を求める。
	// lcm が M を超えるとダメ
	long long lcm_ = 1;
	for (int i = 0; i < N; i++) {
		lcm_ = lcm(lcm_, a[i]);
		if (M < lcm_) {
			cout << 0 << endl;
			return 0;
		}
	}

	// 2^t で割った M = lcm * answer を満たす必要があり、
	// answer は奇数じゃないとダメなので、奇数の個数が答えになる
	M /= lcm_;
	int answer = (M + 1) / 2;

	cout << answer << endl;

	return 0;

}
#include <bits/stdc++.h>
using namespace std;

struct	ModCombi
{
	int64_t	sup, mod;
	vector<int64_t>	fact_vec, inv_vec, if_vec;
	ModCombi(int64_t sup, int64_t mod): sup(sup), mod(mod)
	{
		fact_vec.resize(sup + 1);
		inv_vec.resize(sup + 1);
		if_vec.resize(sup + 1);
		fact_vec.at(0) = fact_vec.at(1) = 1;
		inv_vec.at(1) = 1;
		if_vec.at(0) = if_vec.at(1) = 1;
		for (int64_t i = 2; i <= sup; ++i) {
			fact_vec.at(i) = fact_vec.at(i - 1) * i % mod;
			inv_vec.at(i) = mod - mod / i * inv_vec.at(mod % i) % mod;
			if_vec.at(i) = if_vec.at(i - 1) * inv_vec.at(i) % mod;
		}
	}
	int64_t	calc(int64_t n, int64_t k)
	{
		if (n < 0 || sup < n) return 0;
		if (k < 0 || n < k) return 0;
		return fact_vec.at(n) * if_vec.at(k) % mod * if_vec.at(n - k) % mod;
	}
};

int	main()
{
	const static int64_t	mod = static_cast<int64_t>(1e+9) + 7;
	int	X, Y;
	cin >> X >> Y;
	int num_move0 = 2 * Y - X, num_move1 = 2 * X - Y;
	if ((num_move0 % 3 != 0) || (num_move1 % 3 != 0)) {
		cout << 0 << endl;
		return 0;
	}
	if (num_move0 < 0 || num_move1 < 0) {
		cout << 0 << endl;
		return 0;
	}
	num_move0 /= 3;
	num_move1 /= 3;
	ModCombi	mc(num_move0 + num_move1, mod);
	cout << mc.calc(num_move0 + num_move1, num_move0) << endl;
}
	



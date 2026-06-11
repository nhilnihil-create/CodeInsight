#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <cstdio>

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr i64 MOD = 1000000007;

template<u64 N>
class T
{
	public:
		constexpr T() : data()
		{
			for (i64 i = 0; i <= (i64)N; ++i)
			{
				data[i] = i;
			}
			for (i64 i = 2; i <= (i64)N; ++i)
			{
				if (data[i] != i) continue;
				for (i64 j = i; j <= (i64)N; j += i)
				{
					data[j] = data[j] / i * (i - 1);
				}
			}
			for (i64 i = 1; i <= (i64)N; ++i)
			{
				data[i] = (data[i] + data[i - 1]) % MOD;
			}
		}

		i32 data[N + 1];
};


template<typename T>
constexpr T pow_mod(T a, T b, T m)
{
	T r = 1;
	while (b > 0)
	{
		if ((b & 1) != 0) r = (r * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return r;
}

constexpr T<100000> t;

int main()
{
	i64 n, k;
	scanf("%lld%lld", &n, &k);
	i64 ans = 0;
	for (i64 i = 1; i <= k;)
	{
		i64 j = k / (k / i);
		ans = (ans + pow_mod(k / i, n, MOD) * (t.data[j] + MOD - t.data[i - 1])) % MOD;
		i = j + 1;
	}
	printf("%lld\n", ans);
}

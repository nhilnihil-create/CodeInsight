#include <cstdio>
#include <algorithm>

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using usize = std::size_t;

template<typename T, bool sort = false>
auto divisors(T n) -> std::vector<T> {
	std::vector<T> r;
	T i = 1;
	for (; i * i < n; ++i) {
		if (n % i == 0) {
			r.emplace_back(i);
			r.emplace_back(n / i);
		}
	}
	if (i * i == n) {
		r.emplace_back(i);
	}
	if (sort) {
		std::sort(r.begin(), r.end());
	}
	return r;
}

i32 a[200001];
i32 used[1000001];

auto main() -> i32 {
	i32 n;
	scanf("%d", &n);
	for (i32 i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	std::sort(a, a + n);
	i32 ans = 0;
	for (i32 i = 0; i < n; ++i) {
		bool ok = true;
		if (a[i] != a[i + 1]) {
			for (auto d : divisors(a[i])) {
				if (used[d]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				ans += 1;
			}
		}
		used[a[i]] = true;
	}
	printf("%d\n", ans);
	return 0;
}

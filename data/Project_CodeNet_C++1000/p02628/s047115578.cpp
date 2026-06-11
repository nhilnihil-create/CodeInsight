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
using isize = std::intptr_t;
using usize = std::uintptr_t;

auto main() -> i32 {
	i32 n, k;
	scanf("%d%d", &n, &k);
	i32 p[1000];
	for (i32 i = 0; i < n; ++i) {
		scanf("%d", p + i);
	}
	std::sort(p, p + n);
	i32 ans = 0;
	for (i32 i = 0; i < k; ++i) {
		ans += p[i];
	}
	printf("%d\n", ans);
	return 0;
}

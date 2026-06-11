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

i32 a[200000];

auto main() -> i32 {
	i32 n, k;
	scanf("%d%d", &n, &k);
	for (i32 i = 0; i < k; ++i) {
		scanf("%d", a + i);
	}
	for (i32 i = k; i < n; ++i) {
		scanf("%d", a + i);
		puts(a[i] > a[i - k] ? "Yes": "No");
	}
	return 0;
}

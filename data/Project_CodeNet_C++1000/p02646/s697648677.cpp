#include <cstdio>
#include <cstdint>
#include <algorithm>

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;

auto main() -> i32 {
	i64 a, v, b, w, t;
	scanf("%ld%ld%ld%ld%ld", &a, &v, &b, &w, &t);
	i64 x = std::abs(a - b);
	i64 y = v - w;
	if (y <= 0 || x > y * t) {
		puts("NO");
	} else {
		puts("YES");
	}
	return 0;
}

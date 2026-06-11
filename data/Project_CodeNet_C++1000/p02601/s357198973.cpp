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

auto dfs(i32 k, i32 r, i32 g, i32 b) -> bool {
	bool ok = (g > r) && (b > g);
	if (!ok && k > 0) {
		ok |=
			dfs(k - 1, 2 * r, g, b) |
			dfs(k - 1, r, 2 * g, b) |
			dfs(k - 1, r, g, 2 * b);
	}
	return ok;
}

auto main() -> i32 {
	i32 r, g, b, k;
	scanf("%d%d%d%d", &r, &g, &b, &k);
	bool ok = dfs(k, r, g, b);
	puts(ok ? "Yes" : "No");
	return 0;
}

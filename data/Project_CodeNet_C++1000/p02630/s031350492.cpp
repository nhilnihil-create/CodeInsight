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


i32 cnt[100001];

auto main() -> i32 {
	i64 n;
	scanf("%ld", &n);
	i64 ans = 0;
	for (i32 i = 0; i < n; ++i) {
		i32 a;
		scanf("%d", &a);
		cnt[a] += 1;
		ans += i64(a);
	}
	i32 q;
	scanf("%d", &q);
	for (i32 i = 0; i < q; ++i) {
		i32 b, c;
		scanf("%d%d", &b, &c);
		ans = ans - i64(b) * i64(cnt[b]) + i64(c) * i64(cnt[b]);
		cnt[c] += cnt[b];
		cnt[b] = 0;
		printf("%ld\n", ans);
	}
	return 0;
}

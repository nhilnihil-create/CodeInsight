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
using usize = std::size_t;

auto main() -> i32 {
	i32 n;
	scanf("%d", &n);
	switch (n % 10) {
		case 2:
		case 4:
		case 5:
		case 7:
		case 9: {
			puts("hon");
			break;
		}
		case 0:
		case 1:
		case 6:
		case 8: {
			puts("pon");
			break;
		}
		case 3: {
			puts("bon");
			break;
		}
		default: {
			throw;
		}
	}
	return 0;
}

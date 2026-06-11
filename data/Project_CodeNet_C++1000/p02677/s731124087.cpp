#include <cstdio>
#include <algorithm>
#include <cmath>

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;

constexpr double pi = M_PI;

auto main() -> i32 {
	i32 a, b, h, m;
	scanf("%d%d%d%d", &a, &b, &h, &m);
	double acos = std::cos(2. * pi * ((double)h * 60. + (double)m)/ (12. * 60.));
	double asin = std::sin(2. * pi * ((double)h * 60. + (double)m)/ (12. * 60.));
	double bcos = std::cos(2. * pi * (double)m / 60.);
	double bsin = std::sin(2. * pi * (double)m / 60.);
	double xd = (double)a * acos - (double)b * bcos;
	double yd = (double)a * asin - (double)b * bsin;
	printf("%.12lf\n", std::sqrt(xd * xd + yd * yd));
	return 0;
}

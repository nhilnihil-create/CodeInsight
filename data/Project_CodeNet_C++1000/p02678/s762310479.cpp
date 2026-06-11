#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using i8 = std::int8_t;
using u8 = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;
using usize = std::size_t;

std::vector<i32> edges[100001];
i32 ans[100001];

auto main() -> i32 {
	i32 n, m;
	scanf("%d%d", &n, &m);
	for (i32 i = 0; i < m; ++i) {
		i32 a, b;
		scanf("%d%d", &a, &b);
		edges[a].emplace_back(b);
		edges[b].emplace_back(a);
	}
	std::queue<i32> q;
	q.emplace(1);
	while (q.size() > 0) {
		auto v = q.front();
		q.pop();
		for (auto to : edges[v]) {
			if (ans[to] == 0) {
				ans[to] = v;
				q.emplace(to);
			}
		}
	}
	puts("Yes");
	for (i32 i = 2; i <= n; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

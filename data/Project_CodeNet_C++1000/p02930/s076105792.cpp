#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int n; scanf("%d", &n);

	auto g = make_v<int>(n, n);
	auto solve = [&g](auto&& solve, int l, int r, int level) {
		if(r - l <= 1) return 0;
		
		int mid = (l + r) >> 1;
		for(int i = l; i < mid; i++)
			for(int j = mid; j < r; j++) g[i][j] = level;
		
		solve(solve, l, mid, level + 1);
		solve(solve, mid, r, level + 1);
	};
	solve(solve, 0, n, 1);
	
	for(int i = 0; i < n - 1; i++, printf("\n")) for(int j = i + 1; j < n; j++) printf("%d ", g[i][j]);
	return 0;
}

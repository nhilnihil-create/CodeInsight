#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = std::int_fast64_t;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int n; scanf("%d", &n); std::vector<i64> a(n);
	for(auto& v: a) scanf("%lld", &v);

	std::vector<int> b(n);
	std::iota(begin(b), end(b), 0);
	sort(begin(b), end(b), [&](int i, int j) { return a[i] > a[j]; });

	auto dp = make_v<i64>(n, n);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = -1;
	auto solve = [&](auto&& solve, int l, int r) -> i64 {
		if(l + r >= n) return 0;
		if(dp[l][r] != -1) return dp[l][r];
		
		int L = l, R = n - r - 1, idx = b[l + r];
		i64 A = solve(solve, l + 1, r) + a[idx] * std::abs(idx - L);
		i64 B = solve(solve, l, r + 1) + a[idx] * std::abs(idx - R);
		return dp[l][r] = std::max(A, B);
	};

	printf("%lld\n", solve(solve, 0, 0));	
	return 0;
}

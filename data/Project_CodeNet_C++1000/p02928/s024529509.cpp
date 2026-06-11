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
	int n; i64 k; scanf("%d%lld", &n, &k); std::vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	const int MOD = 1e9 + 7;
	i64 ans = 0, tmp = k * (k - 1) / 2 % MOD;
	for(int i = 0; i < n; i++) {
		i64 A = 0, B = 0;
		for(int j = 0; j < n; j++) A += (a[j] > a[i]);
		for(int j = 0; j < i; j++) B += (a[j] > a[i]);

		(ans += tmp * A + B * k) %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}

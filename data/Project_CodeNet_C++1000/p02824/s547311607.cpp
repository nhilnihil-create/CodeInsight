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
	i64 n, m, v, p; scanf("%lld%lld%lld%lld", &n, &m, &v, &p);
	std::vector<i64> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	sort(begin(a), end(a));

	auto f = [&](int t) {
		if(a[t] + m < a[n - p]) return false;
		i64 V = std::max(0L, v - (p - 1 + t + 1));
		i64 rem = V * m;
		
		for(int i = t + 1; i <= n - p; i++) rem -= std::min(m, (a[t] + m) - a[i]);
		return rem <= 0;
	};

	int ok = n - p, ng = -1;
	while(std::abs(ok - ng) > 1) {
		int mid = (ok + ng) >> 1;

		if(f(mid)) ok = mid;
		else ng = mid;
	}

	printf("%d\n", n - ok);
	return 0;
}

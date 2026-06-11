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
	int n, k; scanf("%d%d", &n, &k); std::vector<int> p(n);
	for(auto& v: p) scanf("%d", &v);
	sort(begin(p), end(p));

	int ans = 0;
	for(int i = 0; i < k; i++) ans += p[i];
	printf("%d\n", ans);
	return 0;
}

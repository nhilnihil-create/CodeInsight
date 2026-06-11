#include <bits/stdc++.h>
#include <atcoder/all>
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
	int n, q; scanf("%d%d", &n, &q);

	atcoder::dsu d(n);
	while(q--) {
		int type, x, y; scanf("%d%d%d", &type, &x, &y);

		if(type) {
			printf("%d\n", d.same(x, y));
		} else {
			d.merge(x, y);
		}
	}
	return 0;
}

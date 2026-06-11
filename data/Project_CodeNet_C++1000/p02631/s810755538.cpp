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
	int n; scanf("%d", &n); std::vector<int> a(n);
	for(auto& v: a) scanf("%d", &v);

	int all = 0;
	for(auto v: a) all = all ^ v;

	for(auto v: a) printf("%d ", all ^ v);
	printf("\n");
	return 0;
}

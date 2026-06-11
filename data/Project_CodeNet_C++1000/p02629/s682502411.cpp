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
	i64 n; scanf("%lld", &n);

	std::string s = "";
	while(n) {
		n--;
		s += (char)('a' + n % 26);
		n /= 26;
	}
	reverse(begin(s), end(s));
	
	printf("%s\n", s.c_str());
	return 0;
}

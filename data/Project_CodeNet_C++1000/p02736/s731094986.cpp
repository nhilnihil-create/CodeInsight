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

int solve(const std::vector<int>& a) {
	int ret = 0;
	const int n = a.size() - 1;
	for(int i = 0; i < a.size(); i++) ret += a[i] * ((n & i) == i);
	return ret & 1;
}

int main() {
	int n; scanf("%d", &n);
	std::string s; cin >> s;

	std::vector<int> a(n);
	for(int i = 0; i < n; i++) a[i] = s[i] - '0';
	{
		std::vector<int> b(n - 1);
		for(int i = 0; i < n; i++) b[i] = std::abs(a[i + 1] - a[i]);
		a = std::move(b);
		n = n - 1;
	}

	int g = solve(a);
	if(g == 1) {
		printf("1\n");
		return 0;
	}

	bool one = false;
	for(auto v: a) one |= (v == 1);
	if(one) {
		printf("0\n");
		return 0;
	}
	for(auto& v: a) v >>= 1;

	printf("%d\n", solve(a) * 2);
	return 0;
}

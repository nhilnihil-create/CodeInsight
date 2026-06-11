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
	int n; scanf("%d", &n);
	std::vector<int> a(n - 1), b(n - 1);
	std::vector<std::vector<int>> g(n);
	for(int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a[i], &b[i]); a[i]--; b[i]--;

		if(b[i] < a[i]) g[a[i]].push_back(b[i]);
		if(a[i] < b[i]) g[b[i]].push_back(a[i]);
	}
	for(int i = 0; i < n; i++) {
		g[i].push_back(-1);
		
		sort(begin(g[i]), end(g[i]));
	}

	i64 ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < (int)g[i].size(); j++) {
			i64 time = g[i][j] - g[i][j - 1];
			i64 cnt  = -(g[i].size() - j - 1);
			ans += time * cnt * (n - i);
		}
		ans += (i64)(i - g[i].back()) * 1 * (n - i);
	}
	
	printf("%lld\n", ans);
	return 0;
}

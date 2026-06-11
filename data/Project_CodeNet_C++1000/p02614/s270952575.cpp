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
	int h, w, k; scanf("%d%d%d", &h, &w, &k);
	std::vector<std::string> s(h);
	for(auto& v: s) cin >> v;

	int ans = 0;
	for(int i = 0; i < (1 << h); i++) {
		for(int j = 0; j < (1 << w); j++) {
			auto t = s;
			for(int k = 0; k < h; k++) {
				if(i >> k & 1) continue;
				for(int l = 0; l < w; l++) t[k][l] = '.';
			}
			for(int l = 0; l < w; l++) {
				if(j >> l & 1) continue;
				for(int k = 0; k < h; k++) t[k][l] = '.';
			}

			int cnt = 0;
			for(int k = 0; k < h; k++) for(int l = 0; l < w; l++) cnt += (t[k][l] == '#');
			ans += (cnt == k);
		}
	}
	printf("%d\n", ans);
	return 0;
}

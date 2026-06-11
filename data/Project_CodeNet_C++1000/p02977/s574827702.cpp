#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
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
	
	if(n < 3) {
		printf("No\n");
		return 0;
	}
	int tmp = (n + 1) % 4;
	
	if(tmp == 1) {
		if((n & (n - 1)) == 0) {
			printf("No\n");
			return 0;
		}
		
		std::vector<std::pair<int, int>> edges;
		edges.push_back({1, 2});
		edges.push_back({2, 3});
		edges.push_back({3, 1 + n});
		edges.push_back({1 + n, 2 + n});
		edges.push_back({2 + n, 3 + n});
		for(int i = 4; i + 5 <= n; i += 4) {
			edges.push_back({edges.back().second, i});
			for(int k = 0; k < 3; k++) edges.push_back({i + k, i + k + 1});
			edges.push_back({i + 3, i + n});
			for(int k = 0; k < 3; k++) edges.push_back({i + k + n, i + k + 1 + n});
		}
		
		int A = n, B = n - 1, C = n - 2, D = n - 3, E = n - 4;
		int X = A ^ B;
		
		edges.push_back({A, X});
		edges.push_back({X, B});
		edges.push_back({B, A + n});
		edges.push_back({B, C});
		edges.push_back({C, D});
		edges.push_back({D, E});
		edges.push_back({E, B + n});
		edges.push_back({B + n, C + n});
		edges.push_back({C + n, D + n});
		edges.push_back({D + n, E + n});
		
//	assert(edges.size() == 2 * n - 1);
		printf("Yes\n");
		for(auto v: edges) printf("%d %d\n", v.first, v.second);
		return 0;
	}
	
	std::vector<std::pair<int, int>> edges;
	edges.push_back({1, 2});
	edges.push_back({2, 3});
	edges.push_back({3, 1 + n});
	edges.push_back({1 + n, 2 + n});
	edges.push_back({2 + n, 3 + n});
	for(int i = 4; i + 3 <= n; i += 4) {
		edges.push_back({edges.back().second, i});
		for(int k = 0; k < 3; k++) edges.push_back({i + k, i + k + 1});
		edges.push_back({i + 3, i + n});
		for(int k = 0; k < 3; k++) edges.push_back({i + k + n, i + k + 1 + n});
	}
	
	if(tmp == 2) {
		int A = n - 1, B = n;

		edges.push_back({A, B});
		edges.push_back({B, 1});
		edges.push_back({1, A + n});
		edges.push_back({A + n, B + n});
	} else if(tmp == 3) {
		int A = n - 2, B = n - 1, C = n;
		
		edges.push_back({A, B});
		edges.push_back({C, B});
		edges.push_back({B, 1});
		edges.push_back({2, C + n});
		edges.push_back({1, A + n});
		edges.push_back({A + n, B + n});
	}
	
	printf("Yes\n");
	for(auto v: edges) printf("%d %d\n", v.first, v.second);
	return 0;
}

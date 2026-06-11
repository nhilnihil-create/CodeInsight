#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>
#include <iterator>

#include <cstdio>
#include <cstdint>
#include <cmath>

using namespace std;

constexpr double pi = 3.141592653589793238462643383279502884197169399375;

namespace shamal{
	template<typename F, typename IndexType, typename TargetType>
	pair<bool, IndexType> lower_bound(F const& func, IndexType left, IndexType right, TargetType const& t){
		while(left <= right){
			auto const mid = left + (right - left) / 2;
			auto const val = func(mid);
			if(val > t){
				right = mid - 1;
			}else if(val < t){
				left = mid + 1;
			}else{ //if(left == right)
				right = mid;
			}
		}

		return {func(left) == t, left};
	}

	template<typename F, typename IndexType, typename TargetType>
	pair<bool, IndexType> binary_search(F const& func, IndexType left, IndexType right, TargetType const& t){
		while(left <= right){
			auto const mid = left + (right - left) / 2;
			auto const val = func(mid);
			if(val > t){
				right = mid - 1;
			}else if(val < t){
				left = mid + 1;
			}else{ //if(left == right)
				return {true, mid};
			}
		};

		return {false, left};
	}
};


int main(void)
{
	int n;
	cin >> n;
	list<pair<double, double>> vertexes;
	vertexes.push_back({0.0, 0.0});
	vertexes.push_back({100.0 / std::pow(3.0, n), 0.0});

	constexpr auto sixty_deg = pi / 3.0;

	while(vertexes.back().first < 100.0){
		auto offset = vertexes.back().first;
		decltype(vertexes) work;
		for(auto const& x : vertexes){
			work.push_back({
					x.first * cos(sixty_deg) - x.second * sin(sixty_deg) + offset,
					x.first * sin(sixty_deg) + x.second * cos(sixty_deg)
			});
		}
		work.pop_front();
		vertexes.merge(work);

		work.clear();
		offset = vertexes.back().first;
		for(auto ite = vertexes.rbegin(); ite != vertexes.rend(); ite++){
			auto const& x = *ite;
			work.push_back({
					2.0 * offset - x.first,
					x.second
			});
		}
		work.pop_front();
		vertexes.merge(work);
	}

	for(auto const& x : vertexes)
		cout << x.first << ' ' << x.second << endl;

	return 0;
}
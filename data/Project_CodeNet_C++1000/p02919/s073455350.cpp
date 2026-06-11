#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>

using std::set;
using std::multiset;
using std::tuple;
using std::vector;
using std::unordered_map;

int64_t mul(int a, int b)
{
	return static_cast<int64_t>(a) * static_cast<int64_t>(b);
}

int64_t solve(int N, const vector<int> &P)
{
	vector<int> X(N + 1);
	for (int i = 0; i < N; ++i) { X[P[i]] = i; }

	multiset<int> set;
	set.emplace(-1);
	set.emplace(-1);
	set.emplace(N);
	set.emplace(N);

	int64_t ans = 0;
	for (int i = N; i >= 1; --i)
	{
		int L[2], R[2];
		auto it0 = set.upper_bound(X[i]);
		{
			auto it = it0;
			R[0] = *it++;
			R[1] = *it++;
		}
		{
			auto it = it0;
			L[0] = *--it;
			L[1] = *--it;
		}
		int64_t sum = 0;
		sum += mul(R[1] - R[0], X[i] - L[0]);
		sum += mul(R[0] - X[i], L[0] - L[1]);
		ans += mul(sum, i);
		set.emplace(X[i]);
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int N;
	std::cin >> N;
	vector<int> P(N);
	for (int i = 0; i < N; ++i) { std::cin >> P[i]; }
	std::cout << solve(N, P) << std::endl;
	return 0;
}

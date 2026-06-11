#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

template<typename T>
constexpr T divide_ceil(T a, T b)
{
	T remainder = a % b;
	return remainder == 0 ? a / b : (a + (b - remainder)) / b;
}

int main()
{
	int N, M;
	cin >> N >> M;

	int ans = 0;
	int num = 1;
	while (num < M)
	{
		num += N - 1;
		++ans;
	}

	cout << ans << endl;
}
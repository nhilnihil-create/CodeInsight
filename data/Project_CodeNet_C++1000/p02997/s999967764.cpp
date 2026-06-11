#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N, K;
	cin >> N >> K;

	if (K > (N - 1) * (N - 2) / 2)
	{
		cout << -1 << endl;
	}
	else
	{
		vector<pair<int, int>> result;
		for (auto i = 2; i <= N; ++i)
		{
			result.push_back(make_pair(1, i));
		}
		auto num = (N - 1) * (N - 2) / 2;
		for (auto i = 2; i < N && num > K; ++i)
		{
			for (auto j = i + 1; j <= N && num > K; ++j)
			{
				result.push_back(make_pair(i, j));
				--num;
			}
		}

		cout << result.size() << endl;
		for (auto i = 0; i < result.size(); ++i)
		{
			cout << result[i].first << " " << result[i].second << endl;
		}
	}

	return 0;
}
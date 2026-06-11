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
	int N;
	cin >> N;

	vector<int> next;
	vector<vector<int>> A;
	for (auto i = 0; i < N; ++i)
	{
		vector<int> temp(N - 1);
		for (auto j = 0; j < N - 1; ++j)
		{
			int a;
			cin >> a;
			temp[N - 2 - j] = a - 1;
		}
		A.push_back(temp);
		next.push_back(i);
	}

	auto cnt = 0;
	while (!next.empty())
	{
		vector<int> list = next;
		next.clear();

		set<int> s;
		auto isCheck = false;
		for (auto i : list)
		{
			if (cnt > 0)
			{
				A[i].pop_back();
			}

			if (A[i].empty())
			{
				continue;
			}

			if (s.find(i) != s.end())
			{
				continue;
			}
			isCheck = true;

			auto j = *A[i].rbegin();
			if (i == *A[j].rbegin())
			{
				next.push_back(i);
				next.push_back(j);
				s.insert(i);
				s.insert(j);
			}
		}

		if (isCheck)
		{
			if (next.empty())
			{
				cnt = -1;
				break;
			}
			else
			{
				++cnt;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
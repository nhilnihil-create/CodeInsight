#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
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
	string N;
	cin >> N;
	auto ans = 0ll;
	auto len = (int)N.length();
	auto next = 0;
	for (auto i = 0; i < len; ++i)
	{
		auto j = len - 1 - i;
		auto val = N[j] - '0' + next;
		if (val > 5)
		{
			next = 1;
			ans += 10 - val;
		}
		else if (val == 5 && j > 0)
		{
			auto nextVal = N[j - 1] - '0';
			if (nextVal >= 5)
			{
				next = 1;
				ans += 10 - val;
			}
			else
			{
				next = 0;
				ans += val;
			}
		}
		else
		{
			next = 0;
			ans += val;
		}
	}
	ans += next;

	cout << ans << endl;

	return 0;
}
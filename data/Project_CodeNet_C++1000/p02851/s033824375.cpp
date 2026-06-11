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
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	map<ll, int> m;
	vector<ll> list;
	m[0] = 1;
	list.push_back(0);
	auto left = 0;
	auto num = 0ll;
	auto sum = 0;
	for (auto right = 0; right < N; ++right)
	{
		if (right + 1 - left >= K)
		{
			--m[list[left]];
			++left;
		}

		sum = (sum + A[right]) % K;
		auto temp = (((sum - right - 1) % K) + K) % K;
		num += m[temp];

		++m[temp];
		list.push_back(temp);
	}

	cout << num << endl;

	return 0;
}
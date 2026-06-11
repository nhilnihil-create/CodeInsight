#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <map>

#define M (int)3e5+1

using namespace std;

int cnt[M];

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		cnt[tmp - 1] ++;
	}

	vector<int> c, p;

	for (int i = 0; i < n; i++)
		if (cnt[i] != 0)
			c.push_back(cnt[i]);

	sort(c.begin(), c.end());

	p.push_back(c.front());

	for (int i = 1; i < c.size(); i++)										//前缀和
		p.push_back(p.back() + c[i]);

	for (int k = 1; k <= n; k++)
	{
		int l = 0, r = n / k, mid;
		while (l != r)
		{
			mid = (l + r) / 2 + 1;
			int id = lower_bound(c.begin(), c.end(), mid) - c.begin();		//二分查找第一个>=m的pos
			int t = c.size() - id;
			if (id != 0)
				t += p[id - 1] / mid;
			if (t >= k)
				l = mid;
			else
				r = mid - 1;
		}
		cout << l << endl;
	}

	return 0;
}
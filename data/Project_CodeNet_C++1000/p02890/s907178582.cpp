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

#define M (long long)3e5 + 10

using namespace std;

long long cnt[M], a[M], sum[M];

int main()
{
	long long n, tot = 0;

	cin >> n;

	for (long long i = 1; i <= n; i++)
	{
		long long tmp;
		cin >> tmp;
		cnt[tmp]++;
	}

	for (long long i = 1; i <= n; i++)
	{
		if (cnt[i] != 0)
			a[++tot] = cnt[i];
	}

	sort(a + 1, a + tot + 1);

	sum[1] = a[1];

	for (long long i = 2; i <= tot; i++)
		sum[i] = sum[i - 1] + a[i];								//前缀和

	for (long long k = 1; k <= n; k++)
	{
		long long l = 1, r = n;
		while (l <= r)
		{
			long long mid = (l + r) >> 1;
			long long pos = upper_bound(a + 1, a + tot + 1, mid) - a;		//返回数组中第一个大于或等于被查数的值的下标
			pos--;											//小于等于mid的数的个数

			if (sum[pos] + (tot - pos) * mid < k * mid)
				r = mid - 1;
			else
				l = mid + 1;
		}
		cout << r << endl;
	}

	return 0;
}

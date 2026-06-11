#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool a[123456 * 2 + 1];

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}

		memset(a, false, sizeof(a));

		int cnt = 0;
		for (int i = 2; i <= n * 2; i++)
		{
			if (a[i] == false)
			{
				if (i > n)
				{
					cnt++;
				}
				for (int j = 1; i * j <= n * 2; j++)
				{
					a[i * j] = true;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
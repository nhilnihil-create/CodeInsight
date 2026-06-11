#include <bits/stdc++.h>
#include<cstring>
using namespace std;

int digit(int n)
{
	int temp = 0;
	while (n > 0)
	{
		n /= 10;
		temp++;
	}
	return temp;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int answer = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		int z = digit(i);
		if (z % 2 != 0)
		{
			answer++;
		}
	}
	cout << answer << endl;
	return 0;
}
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m, n + m)
	{
		int ary[100] = {};
		int p = m;
		int i = 0;
		while (true)
		{
			if (p == 0)
			{
				p = ary[i];
				ary[i] = 0;
			}
			else
			{
				p--;
				ary[i]++;
			}
			if (ary[i] == m)
			{
				cout << i << endl;
				break;
			}
			i++;
			if (i == n) i = 0;
		}
	}
}
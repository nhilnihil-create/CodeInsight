#include <bits/stdc++.h>
using namespace std;

int main()
{
	while (true)
	{
		int h, w;
		cin >> h >> w;
		if (h == 0 && w == 0)
		{
			break;
		}

		for (int i = 0; i < h; i++)
		{
			bool flag = (i % 2 == 0) ? true : false;
			for (int j = 0; j < w; j++)
			{
				string s = (flag) ? "#" : ".";
				cout << s;
				flag = !flag;
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
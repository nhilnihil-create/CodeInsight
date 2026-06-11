#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio == false;
	int h, w;
	while (1)
	{
	cin >> h >> w;
	if (h == 0 && w == 0)break;
	for (int i = 0; i < h; i++)
	{
			if (i == 0 || i == h - 1)
			{
				for (int k = 0; k < w; k++)
				{
					if (k == w - 1)cout << "#" << endl;
					else cout << "#";
				}
			}
			else
			{
		for (int j = 0; j < w; j++)
		{
			if (!i == 0 || !i == h - 1)
			{
			if (j == 0) cout << "#";
			else if (j == w - 1)cout << "#" << endl;
			else cout << ".";
			}
		}
			}
	}
	cout << endl;
	}
	return 0;
}
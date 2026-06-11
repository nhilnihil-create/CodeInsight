#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int h, w, k;
	cin >> h >> w >> k;
	char arr[h + 1][w + 1];
	for(int i = 1;i <= h;i++)
	{
		for(int j = 1;j <= w;j++)
		{
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	for(int c1 = 0;c1 < (1 << h);c1++)
	{
		for(int c2 = 0;c2 < (1 << w);c2++)
		{
			int c = 0;
			for(int i = 0;i < h;i++)
			{
				for(int j = 0;j < w;j++)
				{
					if((!(c1 & (1 << i))) && (!(c2 & (1 << j))))
					{
						if(arr[i + 1][j + 1] == '#')
							c++;
					}
				}
			}
			if(c == k)
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}
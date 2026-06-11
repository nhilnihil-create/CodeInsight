#include <iostream>
#include <vector>
#include <math.h>
#include<string>
using namespace std;

int main() {
	int h, w, K;
	cin >> h >> w >> K;

	string str;
	vector<vector<int>> a(h, vector<int> (w, 0));
	
	for (int i = 0; i < h; i++)
	{
		cin >> str;
		for (int j = 0; j < w; j++)
		{
			if (str[j] == '#')
			{
				a[i][j] = 1;
			}
		}
	}

	int ans = 0;
	
	for (int i = 0; i < (1<<h); i++)
	{
		for (int j = 0; j < (1<<w); j++)
		{
			int cnt = 0;
			for (int k = 0; k < h; k++)
			{
				if (i & (1 << k)) continue;
				for (int l = 0; l < w; l++)
				{
					if (j & (1 << l)) continue;
					if (a[k][l] == 1)cnt++;
				}
			}
			if (cnt == K) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
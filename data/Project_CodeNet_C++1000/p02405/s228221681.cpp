#include <iostream>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

using namespace std;

void solve()
{
	int H, W;
	while (cin >> H >> W, H || W)
	{
		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				if ((i + j) % 2)
				{
					cout << ".";
				}
				else
				{
					cout << "#";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	solve();
	return(0);
}
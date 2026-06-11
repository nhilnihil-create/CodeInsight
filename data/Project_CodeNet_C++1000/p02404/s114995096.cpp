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
		for (int i = 0; i < W; ++i)
		{
			cout << "#";
		}
		cout << endl;
		for (int i = 1; i < H - 1; ++i)
		{
			cout << "#";
			for (int j = 1; j < W - 1; ++j)
			{
				cout << ".";
			}
			cout << "#" << endl;
		}
		for (int i = 0; i < W; ++i)
		{
			cout << "#";
		}
		cout << endl;
		cout << endl;
	}
}

int main()
{
	solve();
	return(0);
}
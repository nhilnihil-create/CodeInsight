//#include "for_cp.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;
#define FOR(i,m,n) for(int i = m; i < n; i++)

int main()
{
	int H, W;
	while (1)
	{
	cin >> H >> W;
	if (H == 0 && W == 0)break;
	FOR(i, 0, H)
	{
		FOR(j, 0, W)
	{
		if (i % 2 == 0 && j % 2 == 0)
		{
			cout << "#";
			if (j == W - 1)cout << endl;
		}
		else if (i % 2 == 0 && j % 2 != 0)
		{
			cout << ".";
			if (j == W - 1)cout << endl;
		}
		else if (i % 2 != 0 && j % 2 == 0)
		{
			cout << ".";
			if (j == W - 1)cout << endl;
		}
		else if (i % 2 != 0 && j % 2 != 0)
		{
			cout << "#";
			if (j == W - 1)cout << endl;
		}
	}
	}
	cout << endl;
	}
}
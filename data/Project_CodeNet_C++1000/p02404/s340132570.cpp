#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <functional>
#include <iomanip>
using namespace std;

//??°?????????????????°

void function()
{
	//??¢??°
}

int main()
{
	int H, W;
	while (cin >> H >> W)
	{
		if (H==0 && W==0)
		{
			break;
		}


		for (int i = 0; i <W; i++)
		{
			cout << "#";
		}

		for (int i = 0; i <H-2; i++)
		{
			cout << endl << "#";

			for (int j = 0; j < W-2; j++)
			{
				cout << ".";

			}
			cout << "#";
		}

		cout << endl;

		for (int i = 0; i <W; i++)
		{
			cout << "#";
		}
		cout << endl <<endl;

	}
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <numeric>

//#include <map>

using namespace std;

class HW{
public:
	int H, W;
};

int main()
{
	vector<HW> vData;

	while (1)
	{
		int H, W;
		cin >> H >> W;
		if (H == 0 && W == 0)break;

		HW thw;
		thw.H = H;
		thw.W = W;
		vData.push_back(thw);
	}

	for (int i = 0; i < vData.size(); i++)
	{
		int H, W;
		H = vData.at(i).H;
		W = vData.at(i).W;
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
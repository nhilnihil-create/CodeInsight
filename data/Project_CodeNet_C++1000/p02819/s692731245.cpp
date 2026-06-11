#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 xx;
	cin >> xx;
	bool flag;
	if(xx == 2)
	{
		cout << '2' << endl;
		return 0;
	}
	while(true)
	{
		flag = true;
		for(int64 ii = 2;ii < sqrt(xx) + 1;ii++)
		{
			if(xx % ii == 0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << xx << endl;
			return 0;
		}
		xx++;
	}
	return 0;
}
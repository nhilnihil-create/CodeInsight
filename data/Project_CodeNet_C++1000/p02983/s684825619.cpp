#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 ll, rr, ans = 3000;
	cin >> ll >> rr;
	for(int64 ii = ll;ii < rr && ii <= ll + 2020;ii++)
	{
		for(int64 jj = ii + 1;jj <= rr && jj <= ii + 2020;jj++)
		{
			if(ans > (ii * jj) % 2019)
			{
				ans = (ii * jj) % 2019;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
// ABC162C.cpp
//#include "pch.h"
#include <iostream>
using namespace std;
int GCD(int i, int j) {
	if (i > 0) {
		j = j % i;
		return GCD(j, i);
	}
	else {
		return j;
	}
}
int main()
{
	int k;
	cin >> k;
	int ans = 0;
	for (int a = 1; a <= k; a++)
	{
		for (int b = 1; b <= k; b++)
		{
			for (int c = 1; c <= k; c++)
			{
				ans += GCD(a, GCD(b, c));
			}
		}
	}
	cout << ans << endl;

}

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}


int main()
{	
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	while (true)
	{
		c -= b;
		if (c <= 0)
		{
			cout << "Yes" << endl;
			break;
		}
		a -= d;
		if (a <= 0)
		{
			cout << "No" << endl;
			break;
		}
	}
	return 0;
}
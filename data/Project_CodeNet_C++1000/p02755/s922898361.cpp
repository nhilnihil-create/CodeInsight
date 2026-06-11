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
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}


int main()
{
	int A, B;
	cin >> A >> B;

	int ans = -1;
	double x1, x2;

	for (int i = 1; i < 1500; ++i)
	{
		x1 = i * 0.08;
		x2 = i * 0.1;
		if (floor(x1) == A && floor(x2) == B)
		{
			ans = i;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
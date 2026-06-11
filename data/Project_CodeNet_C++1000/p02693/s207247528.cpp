#include <algorithm>
#include <cmath>
#include <iostream>
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
	int a, b, k;
	cin >> k;
	cin >> a >> b;

	bool find = false;;
	for (int i = a; i <= b; ++i)
	{
		if (i % k == 0)
		{
			find = true;
			cout << "OK" << endl;
			break;
		}
	}

	if (!find)
	{
		cout << "NG" << endl;
	}

	return 0;
}
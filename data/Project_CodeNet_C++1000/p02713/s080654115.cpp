#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <functional>
#include <map>
#include <math.h>
#include <list>

using namespace std;

#define ll long long int

int gcd(int m, int n)
{
	// 引数に０がある場合は０を返す
	if ((0 == m) || (0 == n))
		return 0;

	while (m != n)
	{
		if (m > n) m = m - n;
		else         n = n - m;
	}
	return m;
}//gcd

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);


	ll k;
	ll sum = 0;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int h = 1; h <= k; h++) {

				sum += gcd(gcd(i, j), gcd(j, h));


			}
		}
	}
	cout << sum << endl;




	return 0;
}

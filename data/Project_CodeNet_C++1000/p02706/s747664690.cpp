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
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> ai(m, 0);
	rep(i, m)
	{
		cin >> ai.at(i);
		n -= ai.at(i);
		if (n < 0)
		{
			n = -1;
			break;
		}
	}

	cout << n << endl;
	return 0;
}
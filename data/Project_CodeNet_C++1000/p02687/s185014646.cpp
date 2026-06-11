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
	string S;

	cin >> S;

	if (S == "ABC")
	{
		cout << "ARC" << endl;
	}
	else
	{
		cout << "ABC" << endl;
	}

	return 0;
}
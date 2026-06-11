#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <map>
#include <cmath>
#define MOD_P 1000000007
#define MOD_Q 998244353
#define PI 3.14159265358979
#define ll long long
using namespace std;

int main()
{
	int x;
	cin >> x;
	int ans = 0;

	for (int i = 1; i < x; i++) {
		int y = x / i;
		if (x % i == 0)y--;
		ans += y;
	}

	printf("%d", ans);

	return 0;
}
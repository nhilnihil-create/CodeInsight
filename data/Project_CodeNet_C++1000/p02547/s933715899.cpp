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
	int a, b;
	int n;
	cin >> n;
	int x = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == b) {
			x++;
		} else {
			x = 0;
		}
		if (x == 3) {
			flag = true;
		}
	}

	printf("%s", flag ? "Yes": "No");

	return 0;
}
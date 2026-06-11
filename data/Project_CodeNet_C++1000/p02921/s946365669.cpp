#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <map>
#include <cmath>
#define MOD_P 1000000007
#define ll long long
using namespace std;

int main()
{
	string pre, result;
	int ans = 0;
	cin >> pre >> result;

	for (int i = 0; i < 3; i++) {
		if (pre[i] == result[i])ans++;
	}

	printf("%d", ans);

	return 0;
}
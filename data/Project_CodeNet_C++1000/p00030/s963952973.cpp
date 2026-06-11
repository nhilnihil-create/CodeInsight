#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <iostream>


using namespace std;

int combinations(int n, int s, int p = 9)
{
	if (n == 0 && s == 0)
		return 1;
	else if (n == 0 && s != 0)
		return 0;

	if (p < 0)
		return 0;

	int res = 0;
	for (int i = p; i >= 0; --i)
		res += combinations(n-1, s-i, i-1);

	return res;
}
int main()
{
	int n, s;
	while (true)
	{
		scanf("%d %d", &n, &s);
		if (s == 0 && n == 0)
			break;

		printf("%d\n", combinations(n, s));
	}
	return 0;
}
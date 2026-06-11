#include <bits/stdc++.h>

using namespace std;

map<uint64_t, uint64_t> memo;

uint64_t rec(uint64_t v)
{
	if (v == 0)
		return 0;
	else if (memo[v])
		return memo[v];
	else
	{
		uint64_t k = 2 * rec(v / 2);
		memo[k] = k + 1;
		return k + 1;
	}
}


int main()
{
	long long int H;
	cin >> H;
	memo[1] = 1;
	cout << rec(H);


	return 0;
}

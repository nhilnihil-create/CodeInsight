#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Vec = vector<int>;
using Graph = vector<Vec>;
#define INF 1000000007
#define MOD 1000000007
#define SEP " "

int		main(void)
{
	int n, k;
	string s;
	cin >> n >> k >> s;
	int c = 1;
	for (int i = 1; i < n; i++)
	{
		if(s[i] != s[i-1])
			c++;
	}
	c -= k * 2;
	cout << n - max(1, c) << endl;
}

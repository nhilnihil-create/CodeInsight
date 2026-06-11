#include <bits/stdc++.h>
using namespace std;

int C[400];
int S[400][30];
int last[30] = {};
int main()
{
	int d;
	cin >> d;

	for (int i = 1; i <= 26; ++i)
		scanf("%d", &C[i]);
	for (int i = 1; i <= d; ++i)
	{
		for (int j = 1; j <= 26; ++j)
			scanf("%d", &S[i][j]);
	}

	int t;
	int v = 0;
	for (int i = 1; i <= d; ++i)
	{
		cin >> t;

		last[t] = i;
		v += S[i][t];

		for (int j = 1; j <= 26; ++j)
			v -= C[j] * (i - last[j]);
		cout << v << '\n';
	}
	return 0;
}
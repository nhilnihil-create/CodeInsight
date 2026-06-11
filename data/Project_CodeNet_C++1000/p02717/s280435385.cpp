#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ara[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> ara[i];
	}
	cout << ara[2] << " " << ara[0] << " " << ara[1] << endl;
	return 0;
}
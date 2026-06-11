#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string sh; cin >> sh;
	stack <char> ch;
	int z = 0;
	for (int i = 1; i < 4; ++i)
	{
		if (sh[i] != sh[0] && z == 0)
		{
			z = i;
		}
		if (sh[i] != sh[0] && sh[i] != sh[z])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	if (z == 0)
		cout<<"No"<<endl;
	else
		cout << "Yes" << endl;
	return 0;
}
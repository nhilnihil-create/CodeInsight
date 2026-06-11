#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
    cin >> n >> m;
	int ara[n], vote = 0;
	double adds = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> ara[i];
		vote += ara[i];
	}
	sort(ara, ara + n, greater<int>());
	adds = (vote*1.0) / (4 * m);
	for (int k = 0; k < m; ++k)
	{
		if (ara[k] < adds)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}

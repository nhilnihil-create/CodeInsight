#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> d1(n), d2(n);
	for (int i = 0; i < n; i++)
	{
		cin >> d1[i] >> d2[i];
	}

	for (int i = 0; i + 2 < n; i++)
	{
		if ((d1[i] == d2[i]) && (d1[i + 1] == d2[i + 1]) && (d1[i + 2] == d2[i + 2]))
		{
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}
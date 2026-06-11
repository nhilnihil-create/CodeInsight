#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int H[100000];
	for (int i = 0; i < n; ++i)
	{
		cin >> H[i];
	}
	int ma = 0;
	for (int i = 0; i < n; ++i)
	{
		ma = max(H[i], ma);
		if (ma >= H[i] + 2)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int infty = static_cast <int> (pow(256, sizeof(int)) / 2 - 1);

int getTheNumberOfCoin(int n, int m, vector<int> &vc)
{
	vector<int> vt;

	for (int j = 0; j <= n; ++j)
	{
		vt.push_back(infty);
	}
	vt[0] = 0;

	for (int i = 0; i < m; ++i)
	{
		for (int j = vc[i]; j <= n; ++j)
		{
			vt[j] = min(vt[j], vt[j - vc[i]] + 1);
		}
	}
	return vt[n];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,m;
	cin >> n >> m;
	cin.ignore();

	int a;
	vector<int> vc;

	for (int i = 0; i < m; ++i)
	{
		cin >> a;
		vc.push_back(a);
	}

	cout << getTheNumberOfCoin(n, m, vc) << endl;

	return 0;
}
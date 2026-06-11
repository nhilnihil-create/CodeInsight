#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m = 0;
	cin >> n >> m;
	vector<int>duck;
	for (int i = 0; i < m; i++)
	{
		int a = 0;
		cin >> a;
		duck.push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		n -= duck[i];
	}
	if (n < 0)n = -1;
	cout << n;
    return 0;
}


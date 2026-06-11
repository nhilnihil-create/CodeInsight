#include "bits/stdc++.h"

using namespace std;
int main()
{
	vector<int> a;
	for (int i = 0; i < 3;i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}
	vector<int>b;
	b = a;
	sort(a.begin(),a.end());
	if (b == a && (a[0] != a[1] && a[1] != a[2]))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
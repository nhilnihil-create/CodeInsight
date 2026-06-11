#include "bits/stdc++.h"

using namespace std;
int main()
{
	vector<int> a;
	for (int i = 0; i < 3; i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	for (auto aa : a)
	{

		cout << aa ;
		if (aa != a[2])cout << " ";

	}
	cout << endl;
	return 0;
}
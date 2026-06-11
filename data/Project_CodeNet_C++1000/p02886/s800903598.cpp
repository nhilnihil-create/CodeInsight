#include <bits/stdc++.h>
using namespace std;


#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int sum = 0, t , d;
	cin >> t;
	vector <int> vec;

	for (int i = 0; i < t; ++i)
	{
		cin >> d;
		vec.push_back(d);
	}
	for (int i = 0; i < t - 1; ++i)
	{
		for (int j = i + 1; j < t; ++j)
		{
			sum += vec[i] * vec[j];
		}
	}
	cout << sum << endl;

	return 0;
}
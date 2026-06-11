#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

int main()
{
	cout << setprecision(6) << fixed;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

/**************************************************************/

	int n;	//The Minkowski’s distance when p = 00
	cin >> n;
	double dbvc[n];	//vcd stands for "difference between vectors components"

	for(int i = 0; i < n; i++)
		cin >> dbvc[i];		//this would be the vector 'x'

	double distance, temp, max_difference = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> temp;	//this would be the vector 'y'
		dbvc[i] = abs(dbvc[i] - temp);
		max_difference = max(max_difference, dbvc[i]);
	}

	for(int j = 0; j < 3; j++)
	{
		distance = 0;
		for(int i = 0; i < n; i++)
			distance+= pow(dbvc[i], j+1);
		cout << pow(distance, 1.0/(j+1)) << endl;
	}
	cout << max_difference << endl;
}


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;

int a, b, c;
string s, t;

int main()
{
	a = 0;
	cin >> a ;
	vector<string> u(a);
	vector<int> x(a);
	rep(i,a)
	{
		cin >> u.at(i)>> x.at(i);
	}
	cin >> t;

	int i = 0, sum = 0;
	while (i < a)
	{
		if (u.at(i) == t)
		{
			for (int j = i + 1; j < a; j++)
				sum += x.at(j);
			break;
		}
      i++;
	}	
	cout << sum << endl;
}

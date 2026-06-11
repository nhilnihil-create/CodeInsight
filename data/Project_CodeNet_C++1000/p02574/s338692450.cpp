#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int max1 = 1000100;
vector<int> a(max1);
vector<int> c(max1);
bool gcdback(int x)
{
	int g = 0;
	for (int i = 0; i < x; i++)
	{
		g = __gcd(g, a[i]);
	}
	if (g == 1)
	{
		return true;
	}
	return false;
}
bool  solveitabdo(int x)
{
	for (int i = 2; i < max1; i++)
	{
		int counter = 0;
		for (int j = i ; j < max1; j += i)
		{

			counter += c[j];
		}
		if (counter > 1)
		{
			return false;
		}
	}
	return true;
}
int main()
{
    int x;
	cin >> x ;
	for (int i = 0; i < x; i++)
	{
		cin >> a[i];
		c[a[i]]++;
	}
	if (solveitabdo(x))
	{
		cout << "pairwise coprime" << endl;
	}
	else if (gcdback(x))
	{
		cout << "setwise coprime" << endl;
	}
	else
	{
		cout << "not coprime" << endl;
	}
}

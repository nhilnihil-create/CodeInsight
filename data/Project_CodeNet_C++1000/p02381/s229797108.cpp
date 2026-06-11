#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;


int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)break;
		double he[1100];
		double heikin, goukei=0;
		for (int i = 0; i < n; i++)
		{
			cin >> he[i];
			goukei += he[i];
		}
		heikin = goukei / n;
		//cout << heikin << endl;
		double f=0;
		for (int i = 0; i < n; i++)
		{
			f += (he[i] - heikin)*(he[i] - heikin);
		}
		cout <<fixed<< sqrt(f/n) << endl;
	}
//cout << "0.0000000000" << endl;
}
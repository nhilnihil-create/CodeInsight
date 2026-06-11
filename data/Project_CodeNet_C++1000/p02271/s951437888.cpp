#include <iostream>
#include<string>
#include<stdio.h>
#include<bitset>

using namespace std;

int main()
{
	int n; cin >> n;
	bool num[40000] = {false}; num[0] = true; int a,max=0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		for (int d = max;  d >=0;  d--)
		{
			if (num[d])num[d + a] = true;
		}
		max += a;
	}
	int s,z; cin >> s;
	for (int i = 0; i < s; i++)
	{
		cin >> z;
		cout << (num[z] ?  "yes" : "no" )<< endl;
	}
	return 0;
}
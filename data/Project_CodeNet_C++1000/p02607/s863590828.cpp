#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <stdio.h>
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pie 3.141592653

using namespace std;


int main()
{
	IO;

	string s;
	int n,tot=0,x;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >>x;
		if (x % 2 != 0 && i % 2 != 0)
			tot++;

	}

	

	cout << tot;
	return 0;
}

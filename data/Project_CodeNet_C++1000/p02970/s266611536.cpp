#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int  main()
{
	int n, d; cin >>  n >> d;
	int range = d *2 + 1;
	if (n % range == 0)
		cout << n / range << endl;
	else 
		cout << (n / range) + 1 << endl;
	return (0);
}
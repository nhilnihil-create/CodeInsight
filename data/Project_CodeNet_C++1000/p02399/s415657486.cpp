#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string.h>


typedef long long int ll;
using namespace std;

int main(void)
{
	double f;
	int d,a,b,r;

	cin >> a >> b;

	d = a / b;
	r = a%b;
	f = (double)a / b;

	cout << d << ' ' << r<<' ';
	printf("%lf\n", f);
	return 0;
}

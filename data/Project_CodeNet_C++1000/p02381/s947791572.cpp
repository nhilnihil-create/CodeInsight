#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    int n;
	int a[1000] = {0};

	while (1)
	{
    cin >> n;
	if (n == 0)
	{
		break;
	}
		double t = 0;
		double dist = 0;
	for ( int i = 0; i < n; i++ )
	{
		cin >> a[i];
		t += a[i];
	}
    double m = t/n;
	for ( int i = 0; i < n; i++ )
	{
		dist += (m-a[i])*(m-a[i]);
	}
    double l = sqrt( dist/n );

    cout << fixed << setprecision(8) << l << "\n" ;
	}

	return 0;
}

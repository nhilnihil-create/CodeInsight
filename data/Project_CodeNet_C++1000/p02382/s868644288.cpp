#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    int n;
	double x[1000] = {0};
	double y[1000] = {0};

    cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> x[i];
	}
		for ( int i = 0; i < n; i++ )
	{
		cin >> y[i];
	}

	double m[1000] = {0};
	double p1 = 0, p2 = 0, p3 = 0, p4 =0, t2 = 0, t3 = 0;
	for ( int i = 0; i < n; i++ )
	{
	m[i] = fabs(x[i]-y[i]);
    p1 += m[i];
	t2 += m[i]*m[i];
	t3 += m[i]*m[i]*m[i];
	}
	p2 = sqrt(t2);
	p3 = pow( t3, 1.0/3 );
	p4 = m[1];
	for ( int i = 0; i < n; i++ )
	{
		m[i] = fabs(x[i]-y[i]);
		if ( p4 < m[i])
		{
			p4 = m[i];
		}
	}
		
    cout << fixed << setprecision(6) << p1 << "\n" ;
	cout << fixed << setprecision(6) << p2 << "\n" ;
	cout << fixed << setprecision(6) << p3 << "\n" ;
	cout << fixed << setprecision(6) << p4 << endl;

	return 0;
}

// AOJ ITP 1_4_B
#include<cstdio>
#include<cmath>

const double pi = acos( -1 );

int main()
{
	double r;
	scanf( "%lf", &r );
	printf( "%.6f %.6f\n", pi*r*r, 2*pi*r );

	return 0;
}
// AOJ ITP 1_4_A
#include<cstdio>

int main()
{
	int a, b;
	scanf( "%d%d", &a, &b );
	printf( "%d %d %.5f\n", a/b, a%b, double(a)/b );

	return 0;
}
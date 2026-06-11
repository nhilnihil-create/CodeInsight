// AOJ ITP1_1_D
#include<cstdio>

int main()
{
	int S;
	scanf( "%d", &S );

	int h = S/3600, s = S%60;
	printf( "%d:%d:%d\n", h, (S-h*3600)/60, s );

	return 0;
}
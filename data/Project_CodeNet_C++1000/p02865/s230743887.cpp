#include<cstdio>
#include<iostream>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
int n;
int solve()
{
	return (n-1)>>1;
}
int main()
{
	scanf("%d",&n);
	printf("%d\n",solve());
	return 0;
}
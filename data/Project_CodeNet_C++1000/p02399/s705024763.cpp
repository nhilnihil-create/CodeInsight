#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double a,b;
	cin>>a>>b;
	int d=a/b;
	int r=a-d*b;
	double f=a/b;
	printf("%d %d %7.5f",d,r,f);
			return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	float c = a,d=b;
	printf("%d %d %.7f",a/b,a%b,double(a)/double(b));

    return 0;
}
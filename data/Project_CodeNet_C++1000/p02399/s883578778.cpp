#include<iostream>//itp14a.cpp
#include<cstdio>
#include<stdio.h>
using namespace std;
int main(void)
{
	int a,b;
	cin>>a>>b;
	printf("%d %d %lf",a/b,a%b,(double)a/b);
	return 0;
}

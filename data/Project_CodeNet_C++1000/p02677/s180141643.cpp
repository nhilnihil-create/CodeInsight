// Problem : C - : (Colon)
// Contest : AtCoder - AtCoder Beginner Contest 168
// URL : https://atcoder.jp/contests/abc168/tasks/abc168_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846264338327950L
int main()
{
	long double a=0,b=0,h=0,m=0;
	cin>>a>>b>>h>>m;
	long double ab=0,length=0;
	ab=abs((long double)(m*6)-(long double)(h*30+m/2.0));
	if(ab>180)
	ab=360-ab;
	length=sqrtl((long double)(a*a+b*b)-(long double)(2*a*b)*(long double)(cosl(ab*PI/180.0)));
	printf("%20.20Lf\n", length);
	return 0;
}

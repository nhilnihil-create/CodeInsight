#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int a, b, d, e;
double f;
cin >> a >> b;
d = a / b;
e = a % b;
f = (double)a / (double)b;
printf("%d %d %lf", d, e, f);
return 0;
}
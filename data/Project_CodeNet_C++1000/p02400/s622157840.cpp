//circle

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
double r,h,s,p=3.141592653589;

cin>>r;

s=p*r*r;
h=2*p*r;

printf("%.8f %.8f\n",s,h);

return 0;
}
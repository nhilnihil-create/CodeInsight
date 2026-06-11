#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double n[4],x,y,d;
	for(int i=0;i<4;++i)
		cin >> n[i];

	x = n[0]-n[2];
	y = n[1]-n[3];

	d = sqrt(pow(x,2)+pow(y,2));

	printf("%.8lf\n",d);

	return 0;
}
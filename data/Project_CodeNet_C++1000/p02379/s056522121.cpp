#include<string>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
	double x1,y1,x2,y2;

	cin >> x1 >> y1 >> x2 >> y2;
	
	double c = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	
	printf("%f\n",c);
	
	return 0;
	
}
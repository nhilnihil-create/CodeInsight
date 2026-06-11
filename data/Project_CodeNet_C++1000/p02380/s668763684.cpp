#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<list>
#include<cctype>
#include<utility>
#include<algorithm>
#include<cctype>
using namespace std;

int main()
{
	double a,b,c;
	cin >> a >> b >> c;
	c = c * M_PI / 180;
	printf("%.6f\n",a*b*sin(c)/2);
	printf("%.6f\n",sqrt(b*b + a*a - 2*a*b*cos(c))+ a + b);
	printf("%.6f\n",b*sin(c));
    return 0;
}
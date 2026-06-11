#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;

int main()
{
    double x1,x2,y1,y2,d;
	cin>>x1>>y1>>x2>>y2;
	d=sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
	//cout<<d<<endl;
	printf("%10f\n",d);
    return 0;
}
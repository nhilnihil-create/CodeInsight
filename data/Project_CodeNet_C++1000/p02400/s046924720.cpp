#include<iostream>
#include<iomanip> 
#define pi 3.1415926535898
using namespace std;
int main()
{
	double r;
	cin>>r;
	
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<pi*r*r<<" "<<2*pi*r<<endl;
	return  0;
 } 

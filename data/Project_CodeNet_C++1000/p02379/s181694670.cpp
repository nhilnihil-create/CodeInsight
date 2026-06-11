#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double a,b,c,d,x,y;
	cin>>a>>b>>c>>d;
	x=a-c;
	x*=x;
	y=b-d;
	y*=y;
	double z = sqrt(x+y);
	cout<<fixed<<z<<endl;
	return 0;
}
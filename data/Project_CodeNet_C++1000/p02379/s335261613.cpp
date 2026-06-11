#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long double p1[2];
	long double p2[2];
	long double a,b;
	
	cin>>p1[0]>>p1[1]>>p2[0]>>p2[1];
	a=(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]);
	b=sqrt(a);
	
	cout<<fixed<<b<<endl;
}
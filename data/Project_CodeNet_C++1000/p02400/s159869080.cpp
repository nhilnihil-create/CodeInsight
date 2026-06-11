#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
	double r;
	cin>>r;
	cout<<fixed<<setprecision(10)<<r*r*3.14159265358979<<endl;
	cout<<fixed<<setprecision(10)<<r*2*3.14159265358979<<endl;
	return 0;
}
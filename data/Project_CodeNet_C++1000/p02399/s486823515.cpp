#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	cout<<a/b<<endl;
	cout<<a-a/b*b<<endl;
	double x=a,y=b;
	cout<<fixed<<setprecision(9)<<x/y<<endl;
	return 0;
}
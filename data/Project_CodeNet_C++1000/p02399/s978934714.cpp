#include<iostream>
using namespace std;

int main(){
	int a,b;
	double c,d;
	cin>>a>>b;
	c=a;
	d=b;
	cout<<a/b<<' '<<a%b<<' ';
	cout.setf(ios::fixed,ios::floatfield);
	cout<<c/d<<endl;
	return 0;
}
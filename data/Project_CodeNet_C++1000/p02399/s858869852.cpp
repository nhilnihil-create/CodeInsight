#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	long long int a,b,c,d;
	double e;
	cin >>a>>b;
	c=a%b;
	d=(a-c)/b;
	e=(double)a/b;
	cout << fixed<< setprecision(20);
	cout << d<<" "<<c<<" "<<e<<"\n";
}
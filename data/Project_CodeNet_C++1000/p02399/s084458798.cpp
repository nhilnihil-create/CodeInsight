#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double c=0;
	int a,b,d=0,e=0;
	cin>>a>>b;
	d=a/b;
	e=a%b;
	c=(double)a/(double)b;
	cout<<d<<" "<<e<<" "<<fixed<<setprecision(5)<<c<<endl;
}
	
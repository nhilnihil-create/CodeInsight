#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int a,b,d,r;
	double f;
	
	cin>>a>>b;
	f=static_cast<double>(a)/static_cast<double>(b);
	cout<<a/b<<" "<<a%b<<" "<<fixed<<f<<"\n";
}
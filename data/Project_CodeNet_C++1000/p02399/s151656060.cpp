#include<iostream>
#include<iomanip>
using namespace std;
	int main(){
int a,b,c,d;
double x;
cin>>a>>b;
c=a/b;
d=a%b;
x=1.00000*a/b;
cout<<c<<" "<<d<<" "<<fixed<<setprecision(5)<<x<<endl;
return 0;
	}
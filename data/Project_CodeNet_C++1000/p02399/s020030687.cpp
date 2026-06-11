#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	cout<<a/b<<endl;
	cout<<a-(b*(a/b))<<endl;
	double c=((double)a)/b;
	cout<<fixed<<setprecision(10)<<c<<endl;
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
#define pi 3.141592653589793283462
int main(){
    int a,b;
	double f,aa,bb;
	cin>>a>>b;
	f=a/b;
	aa=a;
	bb=b;
	cout<<a/b<<" "<<a%b<<" ";
	cout<< fixed << setprecision(10) << aa/bb << "\n";
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
#define pi 3.141592653589793283462
int main(){
	double r;
	cin>>r;
	cout<< fixed << setprecision(10) << r*r*pi<<" " ;
	cout<< fixed << setprecision(10) <<r*2*pi<<endl;
	return 0;
}
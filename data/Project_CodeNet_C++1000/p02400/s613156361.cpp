#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const double Pi=acos(-1);
int main(){
	double r;
	cin>>r;
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<Pi*r*r<<" "<<Pi*2*r<<endl;
	return 0;
}
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	long long a;
	double b;
	cin>>a>>b;
	b=b*(100+0.1);
	a*=(int)b;
	cout<<a/100<<endl;
	return 0;
}
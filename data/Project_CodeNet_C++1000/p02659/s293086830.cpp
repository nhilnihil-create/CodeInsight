#include<iostream>

using namespace std;

int main(){
	long long a;
	double b;
	cin>>a>>b;
	cout<<((long long)(b*100+0.00000000001))*a/100<<'\n'; 
	return 0;
}
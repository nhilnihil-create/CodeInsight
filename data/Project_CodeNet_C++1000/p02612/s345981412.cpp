#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	int a=0;
	for(int i=1000;i<=x+1000;i=i+1000){
		if(i>=x)
		  a=i-x;
		else continue;
		if(a<=500)
		  break;
	}
	cout<<a;
	return 0;
}
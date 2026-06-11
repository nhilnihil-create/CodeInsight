#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,b,c;
	cin>>a>>b>>c;
	int t;
	t=a;
	a=b;
	b=t;
	t=a;
	a=c;
	c=t;
	cout<<a<<" "<<b<<" "<<c<<endl;
	 
	return 0;
 }
#include<iostream>
using namespace std;
int main()
{
	long long a,c,ans;
	double b;
	cin>>a>>b;
	c=b*100+0.1;
	ans=(long long)(a*c)/100;
	cout<<ans<<endl;
	return 0;
}
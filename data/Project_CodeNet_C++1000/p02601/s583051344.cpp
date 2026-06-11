#include <iostream>
using namespace std;
int main()
{
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	int n=0;
	while(b<=a)
	{
		b*=2;
		n++;
	}
	while(b>=c)
	{
		c*=2;
		n++;
	}
	if(n>k)
		cout<<"No"<<endl;
	else if(n<=k)
		cout<<"Yes"<<endl;
	return 0;
}
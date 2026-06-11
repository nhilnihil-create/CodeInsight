# include <iostream>
using namespace std;
int main()
{
	int n,m,a,b;
	a=0; 
	b=0;
	cin>>n>>m;
	if(n>=2)
	{
		a=n*(n-1)/2;
	}
	if(m>=2)
	{
		b=m*(m-1)/2;
	}
	cout<<a+b;
}
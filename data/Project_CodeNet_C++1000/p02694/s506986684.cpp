#include<iostream>
using namespace std;
int main()
{
	long long a;
	int b;
	cin>>a;
	long long c=100;
	b=0;
	while(c<a)
	{
		c=c+c/100;
		b++;
	}
	cout<<b;
	return 0;
}

#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
	long long int a,b,k,c,d;
	cin>>a>>b>>k;
	if(a>=k)
		{
			c=a-k;
			d=b;
		}
	else
		{
			c=0;
			if(a+b>=k)
				d=a+b-k;
			else
				d=0;
		}
		cout<<c<<" "<<d<<endl;
}
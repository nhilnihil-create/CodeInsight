#include <bits/stdc++.h>
using namespace std;
int main() 
{
  long long n,b,c,a;
	cin>>n;
	for(a=sqrt(n)+1;a>0;a--)
	{
		if(n%a==0) 
		{
			b=a;
			break;
		}
	}
	c=n/b;
	cout<<b+c-2;
}

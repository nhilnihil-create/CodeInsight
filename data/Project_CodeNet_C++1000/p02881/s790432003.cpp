# include <iostream>
# include <cmath>
using namespace std;
int main()
{
	long long n,s,p,d;
	cin>>n;
	s=n+1;
	d=sqrt(n);
	for(int i=1; i<=d; i++)
	{
		if(n%i==0)
		{
			if(n/i>=i)
			{
				p=(n/i-1)+(i-1);
				if(p<s)
				{
					s=p;
				}
			}
			else
			{
				break;
			}
		}
	}
	cout<<s; 
}
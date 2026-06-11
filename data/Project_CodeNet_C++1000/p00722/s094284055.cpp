#include<iostream>
using namespace std;
bool isprime(int p)
{
	if(p<2)return 0;
	for(int i=2;i*i<=p;i++)if(p%i<1)return 0;
	return 1;
}
int a,d,n;
main()
{
	while(cin>>a>>d>>n,n)
	{
		int cnt=0;
		for(int i=0;;i++)
		{
			if(isprime(a+d*i))
			{
				cnt++;
				if(cnt==n)
				{
					cout<<a+d*i<<endl;
					break;
				}
			}
		}
	}
}


#include<iostream>
using namespace std;
int main()
{
	int N=123456*2+100;
	bool a[300000]={0};
	for(int i=2;i<N;i++)
	{
		if(a[i]==0)
		{
			for(int j=2;i*j<N;j++)
			{
				a[i*j]=1;
			}
		}
	}
	for(;;)
	{
		int n,ans=0;
		cin>>n;
		if(n==0)break;
		for(int i=n+1;i<=n*2;i++)
		{
			ans+=(int)a[i];
		}
		cout<<n-ans<<endl;
	}
	return 0;
}

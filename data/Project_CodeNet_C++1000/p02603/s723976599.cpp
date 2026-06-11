#include <iostream>
using namespace std;
int main()
{
	long long n,m=0,sum=1000,r=0;
	long long num[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int i=0;i<n-1;i++)
	{	
		if(m==0)
		{
			if(num[i]<num[i+1])
			{
				m=sum/num[i];
				sum=sum-m*num[i];
			}		
		}			
		else if(m>0)
		{
			if(num[i]<=num[i+1])
				continue;
			else if(num[i]>num[i+1])
			{
				sum=m*num[i]+sum;
				m=0;
			}				
		}			
	}
	if(m>0)
		sum=sum+m*num[n-1];
	cout<<sum<<endl;
	return 0;
}
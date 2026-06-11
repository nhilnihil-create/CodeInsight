# include <iostream>
using namespace std;
int main()
{
	long long n,s;
	s=0;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			for(int k=j+1; k<n; k++)
			{
				if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[k]+a[j]>a[i] && a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k])
				{
					s=s+1;
				}
			}
		}
	}
	cout<<s;
}
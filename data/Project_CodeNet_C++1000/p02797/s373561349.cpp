#include<iostream>
using namespace std;
#define int long long int
int32_t main()
{
	int n,k,s;
	cin>>n>>k>>s;
	if(s<=10)
	{
		int j;
		for(j=0;j<k;j++)
		  cout<<s<<" ";
		for(j=k;j<n;j++)
		  cout<<(s+1)<<" ";
		cout<<endl;
	}
	else
	{
		int j;
		for(j=0;j<k;j++)
		  cout<<s<<" ";
		for(j=k;j<n;j++)
		{
			cout<<(s-1)<<" ";
		}
		cout<<endl;
	}
}

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s[n];
	int t[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		cin>>t[i];
	}
	string x;
	cin>>x;
	
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(x==s[i])
		{
			c=i;
			break;
		}
	}
	int sum =0;
	for(int i=c+1;i<n;i++)
	{
		sum+=t[i];
	}
	
cout<<sum;
}
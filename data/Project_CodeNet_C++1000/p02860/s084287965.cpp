#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;
	cin>>n;
	char s[n];
	cin>>s;
	if((n%2)!=0)
	{
		cout<<"No"<<endl;
	}
	else
	{
		char s1[n];
		for(int i=0,j=0;i<n/2;i++,j++)
		{
			s1[j]=s[i];
		}
		int j=n/2;
		for(int i=0;i<n/2;i++,j++)
		{
			s1[j]=s[i];
		}
		int c = strcmp(s,s1);
		if(c)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
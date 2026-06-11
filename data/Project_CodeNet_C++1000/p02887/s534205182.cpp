#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	long long int i,n,p,x,c=0;
	string s;
	cin>>n;
	cin>>s;
	p=s.length();
	for(i=0;i<n-1;i++)
	{
		if(s[i]-s[i+1]!=0)
			c++;
	}
	cout<<c+1<<endl;
}
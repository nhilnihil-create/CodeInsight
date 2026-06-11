#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const long long int  mod  = 1000000007;
int main()
{
	ll n,i,c=0;
	cin>>n;
	string s;
	cin>>s;
	for(i=0;i<s.size()-2;i++)
	{
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')
		{
			c++;
			i=i+2;
		}
	}
	cout<<c;
}

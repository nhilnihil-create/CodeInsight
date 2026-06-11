#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	string s,t;
	cin>>s>>t;
	if(t.length()-1==s.length())
	{
		bool temp=true;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]!=t[i])
			{
				temp=false;
				break;
			}
		}
		if(temp)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	else
	{
		cout<<"No"<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	if(s[n-1]=='s')
	{for(int i=0;i<n;i++)
	cout<<s[i];
	cout<<"es\n";}
	else
	{
		cout<<s<<"s\n";
	}
}

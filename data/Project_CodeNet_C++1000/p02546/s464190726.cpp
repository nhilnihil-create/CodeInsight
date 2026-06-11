#include <bits/stdc++.h>
#define ll long long
#include <string>
using namespace std;

int main()
{
	string s;cin>>s;
	int n=s.length();
	if(s[n-1]=='s')
	{
		cout<<s+"es";
	}
	if(s[n-1]!='s')
	{
		cout<<s+'s';
	}
	return 0;
}

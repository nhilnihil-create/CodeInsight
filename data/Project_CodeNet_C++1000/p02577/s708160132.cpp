#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
int main()
{
	cin>>s;
	int len=s.length();
	long long ans=0;
	for (int i=0;i<len;++i)
	{
		ans+=s[i]-'0';
		ans%=9;
	}
	if (ans%9==0)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
    return 0;
}
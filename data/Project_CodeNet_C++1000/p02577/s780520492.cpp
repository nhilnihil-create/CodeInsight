#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;


int main()
{
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		sum+=s[i]-'0';
	}
	if(sum%9==0)printf("Yes");
	else printf("No");
}
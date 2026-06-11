#include<cstdio>
#include<iostream>
#include<string>
#include <algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	string s,t;
	cin >> s >> t;
	int ans=20000,x=0;
	for(int i=0;i<=s.size()-t.size();i++)
	{
		for(int j=0;j<t.size();j++)
		{
		if(s[i+j]!=t[j]){x++;}
		}
	if(ans>x){ans=x;}
	x=0;
	}
	printf("%d",ans);
}
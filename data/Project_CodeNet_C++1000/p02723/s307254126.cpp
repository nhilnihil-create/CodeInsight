#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,ans;
	cin>>s;
	ans="No";
	if((s[2]==s[3])&&(s[4]==s[5]))
	ans="Yes";
	cout<<ans;
}

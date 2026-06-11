#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	string s,t,u;
	cin>>s>>t>>a>>b>>u;
	for(int i=0;i<s.size();i++)if(s[i]!=u[i])c=1;
	for(int i=0;i<t.size();i++)if(t[i]!=u[i])c=0;
	if(c)cout<<a<<" "<<b-1;
	else cout<<a-1<<" "<<b;
}

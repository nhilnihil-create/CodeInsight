#include<bits/stdc++.h>
using namespace std;
long long f[500005],g[500005]; 
int main()
{
	string s;
	cin>>s;
	long long l=s.size();
	long long sum=0;
	if(s[0]=='<')  f[0]=1;
	for(int i=1;i<l;++i)
	{
	   if(s[i]=='<'&&s[i-1]=='<') f[i]=f[i-1]+1;
	   else if(s[i]=='<') f[i]=1;
	   else f[i]=0;
    } 
    for(int i=l-1;i>=0;--i)
    {
    	if(s[i]=='>'&&s[i+1]=='>') g[i]=g[i+1]+1;
    	else if(s[i]=='>') g[i]=1;
    	else g[i]=0;
	}
	for(int i=0;i<=l;++i)
		sum+=max(f[i-1],g[i]);
	cout<<sum<<endl;
}
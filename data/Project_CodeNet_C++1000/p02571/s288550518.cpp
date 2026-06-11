#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false),cin.tie(0);
#define ll long long
#define inf 0x3f3f3f3f
const int N=105;
//set<string>b;
//set<string>::iterator it;

int main()
{
	IO;
	int len1,len2,i,j,x,ans;
	string s,t;
	cin>>s>>t;
	len1=s.length();
	len2=t.length();
	ans=inf;
	for(i=0;i+len2<=len1;i++)
	{
		x=0;
		for(j=0;j<len2;j++)
		{
			if(s[i+j]!=t[j])
			{
				x++;
			}
		}
		ans=min(ans,x);
	}
	cout<<ans<<endl;
    return 0;
}
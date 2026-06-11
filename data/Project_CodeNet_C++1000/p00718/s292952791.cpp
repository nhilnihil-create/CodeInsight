#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s,t;cin>>s>>t;
		int a=0,b=0,now=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='0'&&s[i]<='9')now=s[i]-48;
			else
			{
				a+=now*(s[i]=='m'?1000:s[i]=='c'?100:s[i]=='x'?10:1);
				now=1;
			}
		}
		for(int i=0;i<t.size();i++)
		{
			if(t[i]>='0'&&t[i]<='9')now=t[i]-48;
			else
			{
				b+=now*(t[i]=='m'?1000:t[i]=='c'?100:t[i]=='x'?10:1);
				now=1;
			}
		}
		a+=b;
		string ans="";
		for(int i=1000;i;i/=10)
		{
			if(a/i%10>1)ans+=a/i%10+48;
			if(a/i%10>0)ans+=i==1?"i":i==10?"x":i==100?"c":"m";
		}
		cout<<ans<<endl;
	}
}

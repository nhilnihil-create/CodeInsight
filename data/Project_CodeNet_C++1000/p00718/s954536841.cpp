#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<cmath>
#include<sstream>
using namespace std;
int  main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s,t;
		cin>>s>>t;
		int num=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='m')
			{
				if(i-1>=0&&'2'<=s[i-1]&&s[i-1]<='9')
				{
					num+=1000*(s[i-1]-'0');
				}
				else
				{
					num+=1000;
				}
			}
			else if(s[i]=='c')
			{
				if(i-1>=0&&'2'<=s[i-1]&&s[i-1]<='9')
				{
					num+=100*(s[i-1]-'0');
				}
				else
				{
					num+=100;
				}
			}
			else if(s[i]=='x')
			{
				if(i-1>=0&&'2'<=s[i-1]&&s[i-1]<='9')
				{
					num+=10*(s[i-1]-'0');
				}
				else
				{
					num+=10;
				}
			}
			else if(s[i]=='i')
			{
				if(i-1>=0&&'2'<=s[i-1]&&s[i-1]<='9')
				{
					num+=(s[i-1]-'0');
				}
				else
				{
					num+=1;
				}
			}
		}
		//cout<<num<<endl;
		for(int i=0;i<t.size();i++)
		{
		if(t[i]=='m')
		{
			if(i-1>=0&&'2'<=t[i-1]&&t[i-1]<='9')
			{
				num+=1000*(t[i-1]-'0');
			}
			else
			{
				num+=1000;
			}
		}
		else if(t[i]=='c')
		{
			if(i-1>=0&&'2'<=t[i-1]&&t[i-1]<='9')
			{
				num+=100*(t[i-1]-'0');
			}
			else
			{
				num+=100;
			}
		}
		else if(t[i]=='x')
		{
			if(i-1>=0&&'2'<=t[i-1]&&t[i-1]<='9')
			{
				num+=10*(t[i-1]-'0');
			}
			else
			{
				num+=10;
			}
		}
		else if(t[i]=='i')
		{
			if(i-1>=0&&'2'<=t[i-1]&&t[i-1]<='9')
			{
				num+=(t[i-1]-'0');
			}
			else
			{
				num+=1;
			}
		}
		}
	//cout<<num<<endl;
	string ans;
	stringstream ss;
	if(num/1000>=1)
	{
		if(num/1000>1)
		{
			ss<<num/1000;
			ans+=ss.str();
		}
		ans+='m';
		num%=1000;
	}
	//ss.clear();
	if(num/100>=1)
	{
		if(num/100>1)
		{
			stringstream ss;
			ss<<num/100;
			ans+=ss.str();
		}
		ans+='c';
		num%=100;
	}
	//ss.clear();
	if(num/10>=1)
	{
		if(num/10>1)
		{
			stringstream ss;
			ss<<num/10;
			ans+=ss.str();
		}
		ans+='x';
		num%=10;
	}
	//if(!ss.empty())ss.clear();
	if(num>=1)
	{
		if(num>1)
		{
			stringstream ss;
			ss<<num;
			ans+=ss.str();
		}
		ans+='i';
		//num%=100;
	}
	//ss.clear();
	cout<<ans<<endl;
	}
	return 0;
}
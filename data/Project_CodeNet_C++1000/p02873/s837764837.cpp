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
	int len;
	len=s.size();
	int cnt=0;long long ans=0;
	int sum1=1,sum2=0;
	while(cnt<=len-1)
	{
		if(s[cnt]==s[cnt+1])
		{
			
			if(s[cnt]=='>')
			{//cout<<sum1<<endl;
				ans+=sum1;sum1++;
				
			}
			else ans+=sum1-1,sum1++;
		}
		else
		{
			if(s[cnt]=='>')
			{
			//	cout<<"aaa"<<sum1<<endl;
				ans+=sum1;
				if(sum2>sum1)ans+=sum2-sum1;
			}
			if(s[cnt]=='<')ans+=sum1-1;
			sum2=sum1;
			sum1=1;
		}
		cnt++;
	}
	if(s[len-1]=='<')ans+=sum2;
	printf("%lld",ans);
}
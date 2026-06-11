#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>


using namespace std;


int main()
{
	string s;
	long long n;
	cin>>s>>n;
	string s1,s2;
	s1=s+s;
	s2=s1+s;
	int sum=1,summ=1;
	long long ans1=0,ans2=0,ans3=0,ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==s[i+1])
		{
			summ++;
		}
		else
		{
			ans1+=summ/2;
			summ=1;
			
		}
	}
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==s1[i+1])
		{
			sum++;
		}
		else
		{
			ans2+=sum/2;
			sum=1;
			
		}
	}
	int num=1;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]==s2[i+1])num++;
		else
		{
			ans3+=num/2;
			num=1;
		}
	}
	if(s[0]!=s[s.size()-1])ans=ans1*n;
	else{
		if(n%2==0)
		{
			ans=ans1+(n/2)*(ans2-ans1)+(n/2-1)*(ans3-ans2);
		}
		else
		{
			ans=ans1+(n/2)*(ans2-ans1)+(n/2)*(ans3-ans2);
		}
	}
	printf("%lld",ans);
}
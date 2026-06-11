#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1010],b[1010];
int c[1010];
void mul_gjd(int rp)
{
	memset(c,0,sizeof(c));
	int len=a[0]+b[0];
	for (int i=1;i<=a[0];++i)
	{
		int upup=0;
		for (int j=1;j<=b[0];++j)
		{
			c[i+j-1]=a[i]*b[j]+upup+c[i+j-1];
			upup=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+b[0]]=upup;
	}
	c[0]=len;
	while ((c[len]==0)&&(len>1))
	{
		len--;
	}
	bool zz=false;
	for (int i=len;i>=1+rp;--i)
	{
		zz=true;
		cout<<c[i];
	}
	if (!zz)
	{
		cout<<0;
	}
	cout<<"\n";
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	a[0]=s1.length();
	b[0]=s2.length();
	for (int i=0;i<a[0];++i)
	{
		a[a[0]-i]=s1[i]-'0';
	}
	int point=0;
	for (int i=0;i<b[0];++i)
	{
		if (s2[i]=='.')
		{
			point=b[0]-1-i;
			int j=i;
			while (j<=b[0])
			{
				s2[j]=s2[j+1];
				j++;
			}
		}
	}
	b[0]--;
	for (int i=0;i<b[0];++i)
	{
		b[b[0]-i]=s2[i]-'0';
	}
	mul_gjd(point);
    return 0;
}
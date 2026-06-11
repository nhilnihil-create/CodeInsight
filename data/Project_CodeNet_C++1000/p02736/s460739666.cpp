#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int a[N],b[N],n;
int sol()
{
	int r=0;
	for(int i=0;i<n;i++)
		r=r^((((n-1)&i)==i)&a[i]);
	return r;
}
int main()
{
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++)
		b[i]=s[i]-'1';
	int fl=0;
	for(int i=0;i<n;i++)
		if(b[i]==1)
			fl=1;
	for(int i=0;i<n;i++)
		a[i]=b[i]&1;
	if(sol())
		puts("1");
	else
	{
		if(fl)
			puts("0");
		else
		{
			for(int i=0;i<n;i++)
				a[i]=b[i]/2;
			if(sol())
				puts("2");
			else
				puts("0");
		}
	}
	return 0;
}
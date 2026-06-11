#include<bits/stdc++.h>
using namespace std;


inline int read()
{
	int num=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {num=(num<<1)+(num<<3)+ch-'0'; ch=getchar();}
	return num*f;
}
int main()
{
	int n=read();
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=n/i;
		if(n%i==0) cnt--;
		ans+=cnt;		
	}		
	printf("%d ",ans);
	
	return 0;
}
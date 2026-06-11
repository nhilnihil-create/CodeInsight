#include<iostream>
#include<cstdio>
using namespace std;
const int N=2002020;
int n,a[N];
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	n=read(); int sum=0;
	for(int i=1;i<=n;i++)
		a[i]=read(),sum^=a[i];
	for(int i=1;i<=n;i++)
		cout<<(a[i]^sum)<<" ";
	return 0;
}
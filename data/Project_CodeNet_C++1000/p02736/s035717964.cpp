#include<iostream>
#include<cstdio> 
#include<cmath>
using namespace std;
int n,k,res,b[1000001],c[1000001];
char a[1000001];
int read()
{
	char c=0;
	int sum=0;
	while (c<'0'||c>'9')
		c=getchar();
	while ('0'<=c&&c<='9')
		sum=sum*10+c-'0',c=getchar();
	return sum;
}
int C(int a,int b)
{
	if (a<b) return 0;
	return 1;
}
int lucas(int a,int b)
{
	if (b==0)
		return 1;
	return C(a%2,b%2)*lucas(a/2,b/2)%2;
}
int main()
{
	n=read();
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<=n;++i) b[i]=a[i]-'0';
	if (n==1)
	{
		printf("%d\n",b[1]);
		return 0;
	}
	for (int i=1;i<=n-1;++i)
		b[i]=abs(b[i]-b[i+1]);
	bool op=0;
	for (int i=1;i<=n-1;++i)
		if (b[i]==1) op=1;
	int res=0;
	if (!op)
	{
		for (int i=1;i<=n-1;++i)
			if (lucas(n-2,i-1))
				res^=(b[i]/2);
		printf("%d\n",res*2);
	}
	else
	{
		for (int i=1;i<=n-1;++i)
			if (lucas(n-2,i-1))
				res^=(b[i]%2);
		printf("%d\n",res);
	}
	return 0;
}
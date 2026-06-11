#include<iostream>
using namespace std;
long long gcd(long long A,long long B)
{
	if(B==0)  return A;
	else  return gcd(B,A%B);
}
int prime[1000100],t;
int p[1000100],tot,use[1000100];
void init();
int main()
{
	init();
	long long A,B;
	cin>>A>>B;
	long long c=gcd(A,B);
	for(int i=1;i<=tot && c>=p[i];i++)
	{
		int k=p[i];
		if(c%k==0)
		{
			prime[++t]=k;
			while(c%k==0)  c/=k;
		}
	}
	if(c>1)  prime[++t]=c;
	t++;  
	cout<<t<<endl;
	return 0;
}
void init()
{
	int n=1000000;
	for(int i=2;i<=n;i++)
	{
		if(!use[i])  p[++tot]=i;
		for(int j=1;p[j]*i<=n && j<=tot;j++)
		{
			use[p[j]*i]=1;
			if(i%p[j]==0)  break;
		}
	}
}
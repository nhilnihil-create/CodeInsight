#include<iostream>
#include<cstdio>

using namespace std;
const int N=2005,Mod=1e9+7;
int f[N]={1},n;

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i-3;j++)
		{
			f[i]=(f[i]+f[j])%Mod;
		}
	}
	printf("%d\n",f[n]);
	return 0;
}
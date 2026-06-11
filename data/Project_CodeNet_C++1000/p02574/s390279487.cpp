#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000000;
int A[MAXN+5];
int G[MAXN+5];

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a%b) ;
}

int main()
{
	int n,x;
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		++A[x];
		ans=gcd(ans,x);
	}	
	int ok=1;
	for(int i=2;i<=MAXN;++i)
	{
		int cnt=0;
		for(int j=i;j<=MAXN;j+=i)
		{
			cnt+=A[j];
		}
		if(cnt>1) ok=0;
	}
	if(ok) printf("pairwise coprime");
	else if(ans==1) printf("setwise coprime");
	else printf("not coprime");
	return 0;
} 
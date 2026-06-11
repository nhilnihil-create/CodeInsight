#include <iostream> 
#include <cstdio>
#define mod 1000000007
#define maxn 100010
#define LL long long

int n,k;

int prime[maxn],not_prime[maxn],phi[maxn],tot;
LL ans;

LL quick_pow(LL a,LL b)
{
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

void linear_shaker(int x)
{
	phi[1]=1;
	
	for(int i=2;i<=x;++i)
	{
		if(!not_prime[i])
		    prime[++tot]=i,phi[i]=i-1;
		
		for(int j=1;i*prime[j]<=x;j++)
		{
			if(i%prime[j]==0)
			    phi[i*prime[j]]=phi[i]*prime[j];
			else 
			    phi[i*prime[j]]=phi[i]*phi[prime[j]];
			    
			not_prime[i*prime[j]]=1;
			
			if(i%prime[j]==0) break;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	linear_shaker(k);
	
	for(int i=1;i<=k;++i)
		ans=(ans+quick_pow(k/i,n)*phi[i]%mod)%mod;
		
	printf("%lld\n",ans);
	
	return 0;
}

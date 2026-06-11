#include<iostream>
#define MAX_L 1000000
#define MAX_SQRT 1000000
using namespace std;
typedef long long ll;
ll a,b;
bool is_prime[MAX_L],is_prime_small[MAX_SQRT];

void segment_sieve(ll a,ll b)
{
	for(int i=0;(ll)i*i<b;i++) is_prime_small[i]=true;
	for(int i=0;i<=b-a;i++)     is_prime[i]=true;

	for(int i=2;(ll)i*i<=b;i++)
	{
		if(is_prime_small[i])
		{
			for(int j=2*i;(ll)j*j<b;j+=i) is_prime_small[j]=false;
			for(ll j=(a+i-1)/i*i;j<=b;j+=i) is_prime[j-a]=false;
		}
	}
}

int main()
{
	//cin>>a>>b;
	while(cin>>a)
	{
		if(a==0) break;
		b=2*a;
		segment_sieve(a,b);
		ll res=0;
		for(int i=0;i<=b-a;i++)
		{
			if(i==0&&is_prime[i]) continue;
			if(is_prime[i]) res++;//cout<<i+a<<" ";
		}
		cout<<res<<endl;
	}
	return 0;
}
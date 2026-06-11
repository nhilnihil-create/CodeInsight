#include<bits/stdc++.h>
const int M=1e9+7;// M=1e9+7;//M=300000;//
const int N=1e5+5;
typedef long long int ll;
using namespace std;
 
ll cnt(0),n,m,x,y,i,j,temp,t,k,ans(0),sum(0),mn(M),mx(-9e9);

bool isPrime(ll a)     //efficient
{
	if(a<=1)
	{
		return false;
	}
	if(a<=3)
	{
		return true;
	}
	if(a%2==0 || a%3==0)
	{
		return false;
	}
		for(int j=5;j*j<=a;j+=6)
		{
			if(a%j==0||a%(j+2)==0)
			{
				return false;
				break;
			}
		}
		return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(i=n;i<=N;i++)
	{
		if(isPrime(i))
		{
			cout<<i;
			return 0;
		}
	}
	
}
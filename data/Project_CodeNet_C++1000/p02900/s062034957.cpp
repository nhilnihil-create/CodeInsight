#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

bool isprime(ll a)
{
	ll count=0;
	for(int i=1;i*i<=a;i++)
	{
		if(a%i==0)count+=2;
		if(i*i==a)count--;
	}
	
	if(count==2)return true;
	else
	return false;
	
}
void solve()
{

	ll a ,b;
	cin>>a>>b;
	
	ll x=__gcd(a,b);

	if(x==1)
	{
		cout<<1;
		return ;
		
	}
	
ll ans=1;
for(int i=2;i<1000000;i++)
{
bool s,f;
s=f=false;
	while(a%i==0)
	{
		a=a/i;
		f=true;
	}
	while(b%i==0)
	{
		b=b/i;
		s=true;
	}
	
	if(s&&f)ans++;

}
if(a>1&&a==b)
ans++;
cout<<ans;

}
int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);

		solve();
	
return 0;

		
	}
	
	
	

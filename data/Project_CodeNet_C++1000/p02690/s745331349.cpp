#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll; 

ll inf =1e9+7;

#define pi 3.14159265358979323846L
bool isprime(ll a)
{
	
	ll cnt=0;	
	for(ll i=1;i*i<a;i++)
	{
		
	 	if(a%i==0)
	 	{
	 		cnt+=2;
		 }
		
		
	}
	
		if(cnt==2)
		return true;
		else
		return false;
		
}
ll mod(ll a)
{
	if(a<inf)return a;
	else
	return a%inf;
}
void solve()
{

ll x;
cin>>x;


for(ll a=-200;a<200;a++)
{	
	ll z=pow(a,5);
	for(ll b=-200;b<200;b++)
	{
		ll y=pow(b,5);
		if(z-y==x )
		{
			cout<<a<<" "<<b;
			return;
		}
	}
}

}

int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);

		solve();
	
return 0;

		
	}
	
	
	

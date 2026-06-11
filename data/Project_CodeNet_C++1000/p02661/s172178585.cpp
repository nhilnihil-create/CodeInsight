#include<bits/stdc++.h>
using namespace std;
typedef  long long ll; 




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
void solve()
{

	
	ll n;
	cin>>n;
	
	ll a[n],b[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	
	sort(a,a+n);
	sort(b,b+n);
	
	
	if(n%2)
	{
		cout<<(b[n/2]-a[n/2])+1;
	}
	else
	{
		
		cout<< (b[n/2]+b[n/2 -1]-a[n/2]-a[n/2 -1]+1) ;
	}
		





	
	
	
	
		
	


}


int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);


		solve();
	
return 0;

		
	}
	
	
	

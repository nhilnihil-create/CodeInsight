#include<bits/stdc++.h>
using namespace std;
typedef  long long ll; 

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

	ll A,B,H,M;
	cin>>A>>B>>H>>M;
	
	
	long double angle1=((long double)H/6.0)+((long double)M/(12.0*30.0))-((long double)M/30.0);
	angle1*=pi;
	long double angle2=2*pi-angle1;
	
	angle1=min(angle1,angle2);
	



	long double z=(A*A)+(B*B )-(2*A*B )*cos(angle1);
	z=sqrt(z);
	
	cout<<setprecision(20)<<z;
	
	
	

}

int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);

		solve();
	
return 0;

		
	}
	
	
	

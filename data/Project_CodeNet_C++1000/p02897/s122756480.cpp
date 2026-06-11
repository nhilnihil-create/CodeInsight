#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll selfadd(ll a,ll b)
{
	if(a<b)
	return a;
	else return a%b;
}
void solve()
{

	ll	 n;
	
	cin>>n;
	double x=(double)n;
	
	if(n%2==0)cout<<0.5;
	else
	cout<<setprecision(12)<<((n/2)+1)/x;
		
		
	
	
	
	
	}
		
		


int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);

		solve();
	
return 0;

		
	}
	
	
	

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

	ll	 n,k,count=0;
	
	cin>>n>>k;
	
	ll a[n];
	for(auto &i:a)
	{
		cin>>i;
		if(i>=k)count++;
	}
		
		
		cout<<count;
	
	
	
	
	}
		
		


int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);

		solve();
	
return 0;

		
	}
	
	
	

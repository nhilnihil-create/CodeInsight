#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

using namespace std ;

int main()
{
	ll n;
	cin>>n;
	ll A[n];
	for(ll i=0 ; i<n;  i++)
		cin>>A[i];
	ll total= 0 ;
	ll h=-1 ;
	for(ll i=0 ; i<n; i++)
	{
		h = max(h,A[i]);
		total+=(h-A[i]);
	}
	cout<<total;
}

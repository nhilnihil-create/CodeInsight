#include "bits/stdc++.h"
using namespace std;
#define ll long long int
bool possible(vector<ll> &a,int k,ll can)
{

 ll count=0;
 int n=a.size();

 for(int i=0;i<n;i++)
 {	
 	if(a[i]<=can)
 		continue;

 	count+=(a[i]/can);
 }



 return (count<=k);

}


int main()
{
	int n,k;
	cin>>n>>k;
	vector<ll> a(n);
	ll mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}

	ll l=1,h=mx+1;


	ll opt=1e18;

	while(l<=h)
	{
		ll mid=(l+h)/2;

		if(possible(a,k,mid))
		{
			opt=min(opt,mid);
			h=mid-1;
		}
		else
		{
			l=mid+1;
		}

		//cout<<mid<<endl;


	}

	cout<<opt<<endl;


	return 0;
}
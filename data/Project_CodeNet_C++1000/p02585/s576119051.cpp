/*====================================
Auther:    Shyam Makwana
Problem:   abc175_d.cpp
====================================*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	long long int n,m;
	cin>>n>>m;
	vector<ll> per(n+1);
	vector<ll> point(n+1);

	for(int i=1;i<=n;i++)
		cin>>per[i];

	for(int i=1;i<=n;i++)
		cin>>point[i];

	ll max1=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		ll c1=0,csum=0;
		while(true)
		{
			c1++;
			csum+=point[j];						
			j=per[j];
			if(j==i)
				break;
		}		
		
		ll cur=0;		
		if(csum<=0)
		{		
			j=i;
			while(true)
			{
				cur+=point[j];
				max1=max(max1,cur);
				j=per[j];
				if(j==i)
					break;
			}			
		}
		else
		{
			ll k=m;
			ll num=k/c1;
			num--;
			cur=num*csum;
			k-=(num*c1);
			max1=max(max1,cur);
			j=i;
			while(k--)
			{
				cur+=point[j];				
				max1=max(max1,cur);
				j=per[j];
				if(j==i)
					break;
			}
			while(k--)
			{
				cur+=point[j];				
				max1=max(max1,cur);
				j=per[j];
				if(j==i)
					break;
			}
		}
	}
	cout<<max1;
}
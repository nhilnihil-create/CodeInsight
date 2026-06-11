#include<bits/stdc++.h>

using namespace std;
int a[200050],n,k;
bool check(int mid)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
      if(a[i]>mid)
		 ans+=a[i]/mid;
		
	}
  if(ans>k) return 0;
	return 1;
}
int main()
{
	
	cin>>n>>k;
	int l=1,r=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r=max(a[i],r);
	}
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			r=mid-1;
			
		}
		else l=mid+1;
	}
  
  if(check(l))
	cout<<l;
  else
    cout<<l-1;
	return 0;
} 

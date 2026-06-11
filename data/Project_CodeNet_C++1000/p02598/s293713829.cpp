#include<bits/stdc++.h>
using namespace std;
int n,k,has,arr[200005];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>arr[i];
	int l=1,r=1000000000;
	while(l<=r)
	{
		int mid=(l+r)/2,now=k;
		for(int i=1;i<=n;i++)
		{
			if(arr[i]<=mid) continue;
			else 
			{
				now-=arr[i]/mid;
				if(now<0) break;
			}
		}
		//cout<<now<<" "<<mid<<endl;
		if(now<0) l=mid+1;
		else has=mid,r=mid-1;
	}
	cout<<has<<endl;
}
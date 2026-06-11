#include<bits/stdc++.h>
using namespace std;
long long int a[200005],sum[200005];
int main()
{
	map<long long int ,long long int >mp;
	int n,k;
	long long int ans=0;
	cin>>n>>k;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(i>=k) {
			mp[(sum[i-k]-(i-k))%k]--;
		} 
		if(mp.count((sum[i]-i)%k))
		{
		ans+=mp[(sum[i]-i)%k];
	    }
		mp[(sum[i]-i)%k]++;
	}
	cout<<ans<<endl;
	return 0;
}
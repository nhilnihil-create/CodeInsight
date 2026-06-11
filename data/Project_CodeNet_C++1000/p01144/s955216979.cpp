#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n,m;
main()
{
	while(cin>>n>>m,n)
	{
		int cnt[11]={};
		for(int i=0;i<n;i++)
		{
			int d,p;cin>>d>>p;
			cnt[p]+=d;
		}
		for(int i=10;i>=0&&m;i--)
		{
			if(m>cnt[i])
			{
				m-=cnt[i];cnt[i]=0;
			}
			else
			{
				cnt[i]-=m;
				m=0;
			}
		}
		long long ans=0;
		for(int i=0;i<=10;i++)ans+=cnt[i]*i;
		cout<<ans<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
long long n,k,vis[5005],p[5005],c[5005],sum[5005],ans=-1e18;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
		cin>>p[i];
    for(int i=1;i<=n;i++)
		cin>>c[i];
    for(int i=1;i<=n;i++)
	{
        long long s=c[i];
        vector<long long> t; 
		t.push_back(s);
        for(int j=p[i];j!=i;j=p[j])
        {
			s+=c[j];
			t.push_back(s);
		}
		int l=t.size();
        for(int j=0;j<l;j++)
		{
            long long rest=k-j-1;
            if(rest<0)
				break;
			
            ans=max(ans,t[j]+(rest/l)*max(s,0LL));
        }
    }
    cout<<ans<<endl;
    return 0;
}
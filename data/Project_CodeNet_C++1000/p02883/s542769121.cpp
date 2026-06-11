#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long  n,k;
    cin>>n>>k;
    vector<long long>a(n),f(n);
    for(int i=0;i<n;i++)
	{
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
	{
        cin>>f[i];
    }
    sort(a.begin(),a.end());
    sort(f.begin(),f.end());
	reverse(f.begin(),f.end());
    long long  cnt = -1;
    long long  ans = 1e13+10;
    while (abs(ans - cnt)>1)
	{
        long long  mid = (ans + cnt) / 2;
        long long  ss = 0;
        for(int i=0;i<n;i++){
            if(a[i]*f[i]>mid)
			{
                ss+=a[i]-(mid/f[i]);
            }
        }
        if (ss<=k)
		{
			ans=mid;
		}
        else
		{
			cnt=mid;
		}
    }
    cout<<ans<<endl;
    return 0;
}
